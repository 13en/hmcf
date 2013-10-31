<?php

require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// HEADTEACHER
$headTeacher = '';
if(is_file($this->Config->PATH->IMG . 'parents/headteacher.jpg')) {

	$htName = isset($pageElements->headteacher) && $pageElements->headteacher ? $pageElements->headteacher : '';

	$headTeacher = "<div class='headteacher'><img src='{$this->Config->URL->IMG}parents/headteacher.jpg' width='210' height='210' alt='{$htName}' />";
	if($htName) {
		$headTeacher .= "<div class='overlay'>{$htName}</div>";
	}
	$headTeacher .= "</div>";

}


// SET VARIABLES
$this->pageContent->h1 = 'Parents';

$this->pageContent->preFold = <<<EOF

				<div class="bg_img"></div>

				{$quote}

EOF;

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->welcome}

					<h2>School Hours</h2>
					<h3>Infants</h3>
					<table class="data">

						<tr class="alt1 start">
							<th>Morning Session</th>
							<td>{$pageElements->infant_hours->r1}</td>
						</tr>

						<tr class="alt2">
							<th>Lunch</th>
							<td>{$pageElements->infant_hours->r2}</td>
						</tr>

						<tr class="alt1 end">
							<th>Afternoon Session</th>
							<td>{$pageElements->infant_hours->r3}</td>
						</tr>

					</table>

					<h3>Juniors</h3>
					<table class="data">

						<tr class="alt1 start">
							<th>Morning Session</th>
							<td>{$pageElements->junior_hours->r1}</td>
						</tr>

						<tr class="alt2">
							<th>Lunch</th>
							<td>{$pageElements->junior_hours->r2}</td>
						</tr>

						<tr class="alt1 end">
							<th>Afternoon Session</th>
							<td>{$pageElements->junior_hours->r3}</td>
						</tr>

					</table>

					{$pageElements->main}

				</div>

EOF;

$this->pageContent->subContent = <<<EOF

				<div class="sub_content">

					{$headTeacher}

					{$links}

				</div>
EOF;

?>