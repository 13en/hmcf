<?php

spl_autoload_register(function($class) {

	require_once('class.' . $class . '.inc');

});


/**
 * Extends base class to add in site-specific functionality
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
class HMCF extends HMCFBase {

	public function output() {

		$this->pageContent = new stdClass();

		if(strpos($this->pageID, 'blog__') === 0) {

			$this->getOutputDynamic('blog.entry');

		} else {

			$this->getOutputGeneral();

		}

	}

	public function process() {

		switch($_GET['HMCF_PROCESS']) {

			case 'mobile-alerts':

				$this->setMobileAlert($_POST);
				break;

		}

	}

	private function setMobileAlert($data) {

		$err = array();

		if(!isset($data['agreement'])) {

			$err[] = 'Agreement tick box';

		} elseif(isset($data['name'], $data['mobile'], $data['email'])) {

			$name = trim($data['name']);
			if(!$name)
				$err[] = 'Your name';

			$mobile = trim($data['mobile']);
			if(!$mobile)
				$err[] = 'Mobile number';

			$new_num = $data['new_num'] == 1 ? '(this is a new number)' : '';

			$email = trim($data['email']);
			if(!$email)
				$err[] = 'e-mail address';

			$child = array();
			$class = array();

			if(isset($data['child1'], $data['class1'])) {

				$thischild = trim($data['child1']);
				$thisclass = trim($data['class1']);

				if((!$thischild) || (!$thisclass))
					$err[] = 'Details for first child';

				$child[] = $thischild;
				$class[] = $thisclass;

			}

			for($i = 2; $i <= 10; $i++) { // noone has more than 10 kids do they? surely? ;o)

				if(isset($data['child' . $i], $data['class' . $i])) {

					$thischild = trim($data['child' . $i]);
					$thisclass = trim($data['class' . $i]);

					if($thischild XOR $thisclass) {

						$err[] = 'Details for child ' . $i;

					} elseif($thischild && $thisclass) {

						$child[] = $thischild;
						$class[] = $thisclass;

					}

				}

			}

		} else {

			$err[] = 'All fields';

		}

		$qs = '';
		if(count($err) > 0) {

			$qs = '?' . http_build_query(array('e' => $err));

		} else {

			$children = array();
			foreach($child as $idx => $val) {

				$children[] = $child[$idx] . ' (Class: ' . $class[$idx] . ')';

			}
			$children = implode("\n", $children);

			$subject = 'New mobile alert request received';
			$msg = <<<EOF

The following mobile alert request has been received via the school website:

Sender's name: $name
Mobile number: $mobile $new_num \n
e-mail address: $email

Child:
$children
EOF;
			mail($this->Config->EMAIL->TO, $subject, $msg, 'From: ' . $this->Config->LANG->SITE_NAME .' <' . $this->Config->EMAIL->FROM .'>');
			$qs = '?sent';

		}

		header('Location: ' . $this->Config->URL->WEB . 'mobile-alerts/' . $qs);
		exit;

	}

}


/**
 * Extends data class to add in site-specific functionality
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
class Data extends HMCFData {


}

?>