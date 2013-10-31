<?php

$bg_imgs = array();
$quotes = array();
$bullets = array();
$qid = 0;
foreach($pageElements->quotes as $quote) {

	$qid++;
//	$sqid = str_pad($qid, 2, '0', STR_PAD_LEFT);

	if(is_file($this->Config->PATH->IMG . 'home/bg-' . $qid .'.jpg')) {

		$cite = isset($quote->c) && $quote->c ? " ({$quote->c})" : '';

		$bg_imgs[] = "<div class='id{$qid}'><img src='{$this->Config->URL->IMG}home/bg-{$qid}.jpg' width='1600' height='992' alt='Image {$qid}' style='display:none;' /></div>";
		$quotes[] = "<div class='id{$qid}'><q>{$quote->q}</q>{$cite}</div>";
		$bullets[] = "<li id='bullet{$qid}'><a href='#'><span class='bullet'></span><span class='hide'>Quote {$qid}</span></a></li>";

	}

}
$bg_imgs = implode("\n", $bg_imgs);
$quotes = implode("\n", $quotes);
$bullets = implode("\n", $bullets);

$this->pageContent->h1 = 'Welcome to our website';

$this->pageContent->preFold = <<<EOF

				<div class="bg_imgs">
					{$bg_imgs}
				</div>

				<div class="home-quotes">
					<div class="quote-marks"></div>
						<div class="quotes">
							{$quotes}
						</div>
					<ul class="nav">
						{$bullets}
					</ul>
				</div>

EOF;

if(isset($pageElements->alert) && $pageElements->alert) {

	$this->pageContent->alert = <<<EOF

<div class="alert">
	<div class="title"><div class="inner">ALERT &gt;</div></div>
	<div class="msg">{$pageElements->alert}</div>
	<br class="clear">
</div>

EOF;

}

$this->pageContent->foot = <<<EOF

<script src="{$this->Config->URL->JS}hive.home.js"></script>
<script>$('#core_full section#core_content div.alert .title .inner').pulsate();</script>

EOF;

?>