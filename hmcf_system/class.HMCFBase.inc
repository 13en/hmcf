<?php

/**
 * Base constructor class
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
abstract class HMCFBase {

	public
		$pageContent = null,
		$pageID = null,
		$parentPageID = null,
		$pagePath = null,
		$updateID = '',
		$Config = null;


	protected
		$Data = null;


	public function __construct() {

		$this->Config = new Config();
		$this->Data = new Data($this->Config->DB);
		$this->setPageParameters($_GET);

	}


	protected function setPageParameters($GET) {

		$this->pageID = isset($GET['HMCF_PAGE']) ? $GET['HMCF_PAGE'] : 'home';

		$pageParts = explode('__', $this->pageID);
		$this->parentPageID = $pageParts[0];
		$this->pagePath = str_replace('_', '-', str_replace('__', '/', $this->pageID));


		$this->pageID = str_replace('-', '_', $this->pageID);

	}


	protected function getOutputGeneral() {

		$pageElements = $this->Data->getPageContent($this->pageID);

		if(isset($pageElements->updated)) {

			$this->updateID = dechex($pageElements->updated);

		} else {

			$this->updateID = '';

		}

		$template = $this->Config->PATH->PAGES . $this->pageID . '.tpl';
		if(is_file($template)) {

			require_once $template;

		}

	}


	protected function getOutputDynamic($tpl) {

		$pageElements = $this->Data->getPageContent($this->pageID);

		if(isset($pageElements->updated)) {

			$this->updateID = dechex($pageElements->updated);

		} else {

			$this->updateID = '';

		}

		$template = $this->Config->PATH->PAGES . $tpl . '.tpl';
		if(is_file($template)) {

			require_once $template;

		}

	}


	public function getPageElement($var) {

		return isset($this->pageContent->$var) ? $this->pageContent->$var : null;

	}
	public function echoPageElement($var) {

		$str = $this->getPageElement($var);
		echo isset($str) ? $str : '';

	}


	protected function strToFilename($str) {

		$return = trim($str);
		$return = strtolower($return);
		$return = preg_replace('/[^a-z0-9]/', '-', $return);
		$return = preg_replace('/-+/', '-', $return);
		$return = trim($return, '-');

		return $return;

	}

}

?>