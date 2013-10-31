<?php


// DOCUMENTS
$pdocs = array();
if(isset($pageElements->pdocs) && is_array($pageElements->pdocs)) {

	foreach($pageElements->pdocs as $l) {

		if(isset($l->title, $l->file) && is_file($this->Config->PATH->DOCS . $this->pagePath . '/' . $l->file)) {

			$title = nl2br($l->title, false);

			$pdocs[] = "<div class='download-link fl'><a href='{$this->Config->URL->DOCS}{$this->pagePath}/{$l->file}'><span class='txt'>{$title}</span><span class='icon'></span><br class='clear'></a></div>";

		}

	}

}
$pdocs = implode("\n", $pdocs);


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'School Mailings';

$this->pageContent->preFold = <<<EOF

				<div class="bg_img"></div>

				{$quote}

EOF;

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

				<div class="main_content wide">

					{$pdocs}

					<div class="clear"></div>

				</div>

EOF;

?>