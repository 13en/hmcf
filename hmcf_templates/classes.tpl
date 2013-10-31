<?php

require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Classes';

$this->pageContent->preFold = <<<EOF

				<div class="bg_img"></div>

				{$quote}

EOF;

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

				<div class="main_content wide">

					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/nursery/"><span class="txt">Nursery</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/reception/"><span class="txt">Reception</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y1/"><span class="txt">Y1</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y2/"><span class="txt">Y2</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y3/"><span class="txt">Y3</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y4/"><span class="txt">Y4</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y5/"><span class="txt">Y5</span><span class="icon"></span><br class="clear"></a></div>
					<div class="internal-link fl"><a href="{$this->Config->URL->WEB}classes/y6/"><span class="txt">Y6</span><span class="icon"></span><br class="clear"></a></div>

					<div class="clear"></div>

				</div>

EOF;

?>