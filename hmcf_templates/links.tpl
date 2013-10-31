<?php


// LINKS
$plinks = array();
if(isset($pageElements->plinks) && is_array($pageElements->plinks)) {

	foreach($pageElements->plinks as $l) {

		if(isset($l->title, $l->file)) {

			$title = nl2br($l->title, false);

			$plinks[] = "<div class='external-link fl'><a href='{$l->file}' target='_blank'><span class='txt'>{$title}</span><span class='icon'></span><br class='clear'></a></div>";

		}

	}

}
$plinks = implode("\n", $plinks);


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Links';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

				<div class="main_content wide">

					{$plinks}

					<div class="clear"></div>

				</div>

EOF;

?>