<?php


// QUOTE
$quote = '';
if(isset($pageElements->quote->q)) {

	$quote = "<div class='single-quote'><div class='quote-marks'></div><div class='quote'><q>{$pageElements->quote->q}</q>" . (isset($pageElements->quote->c) && $pageElements->quote->c ? "<br>({$pageElements->quote->c})" : '') . "</div></div>";

}


// LINKS
$links = array();
if(isset($pageElements->links) && is_array($pageElements->links)) {

	foreach($pageElements->links as $l) {

		if(isset($l->type, $l->title, $l->file)) {

			$title = nl2br($l->title, false);

			switch($l->type) {

				case 'download':

					if(is_file($this->Config->PATH->DOCS . $this->pagePath . '/' . $l->file)) {

						$links[] = "<div class='download-link'><a href='{$this->Config->URL->DOCS}{$this->pagePath}/{$l->file}'><span class='txt'>{$title}</span><span class='icon'></span><br class='clear'></a></div>";

					}
					break;

				case 'internal':

					$links[] = "<div class='internal-link'><a href='{$this->Config->URL->WEB}{$l->file}'><span class='txt'>{$title}</span><span class='icon'></span><br class='clear'></a></div>";
					break;

				case 'external':

					$links[] = "<div class='external-link'><a href='{$l->file}' target='_blank'><span class='txt'>{$title}</span><span class='icon'></span><br class='clear'></a></div>";
					break;

			}

		}

	}

}
$links = implode("\n", $links);


?>