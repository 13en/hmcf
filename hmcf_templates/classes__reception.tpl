<?php

require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Reception';

$this->pageContent->preFold = <<<EOF

				<div class="bg_img"></div>

				{$quote}

EOF;

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

EOF;

$this->pageContent->subContent = <<<EOF

				<div class="sub_content">

					{$links}

				</div>
EOF;

?>