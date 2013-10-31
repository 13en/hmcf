<?php


// NEWS
$news = array();
if(isset($pageElements->news) && is_array($pageElements->news)) {

	foreach($pageElements->news as $obj) {

		$obj->title = htmlentities($obj->title, ENT_QUOTES | ENT_HTML5);
		$obj->author = htmlentities($obj->author, ENT_QUOTES | ENT_HTML5);

		$imagePath = "{$this->Config->PATH->IMG}news/{$obj->image}";
		$image = is_file($imagePath) ? "<img class='newsimage' src='{$this->Config->URL->IMG}news/{$obj->image}' width='150' alt='{$obj->title}' />" : '';

		$author = $obj->author ? "<p class='italic'>By {$obj->author}</p>" : '';

		$news[] = <<<EOF
					{$image}
					<div class="newstext">
						<p class="subheading">{$obj->title}</p>
						{$author}
						{$obj->main}
					</div>
EOF;


	}

}
$news = implode("\n<div class='divider clear'></div>\n", $news);


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Latest News';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$news}

					<div class="clear"></div>

				</div>

EOF;

$this->pageContent->subContent = <<<EOF

				<div class="sub_content">

					{$links}

				</div>
EOF;

?>