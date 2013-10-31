<?php


// SCHOOL DATES
$school_dates = array('tabs' => '', 'tables' => '');
if(isset($pageElements->school_dates) && is_array($pageElements->school_dates)) {

	$tabs = array();
	$tables = array();
	$first_tab = true;

	foreach($pageElements->school_dates as $tabID => $obj) {

		$ref = 'y' . ($tabID + 1);
		$current = $first_tab ? ' current' : '';
		$hide = $first_tab ? '' : ' hide';
		$lastRow = count($obj->end->dates);

		$tabs[] = "<div class='season{$current} {$ref}'><h3>{$obj->start->label} - {$obj->end->label}</h3></div>";

		$rows = array();
		$rows[] = "<table class='data {$ref}{$hide}'><tr class='start blue'><th class='third'><span class='bold'>Term</span></th><th class='third'><span class='bold'>Closes at 3.30pm</span></th><th><span class='bold'>Re-opens at 8.50am</span></th></tr>";
		$rows[] = "<tr class='section_header'><td class='red'><span class='bold'>{$obj->start->label}</span></td><td>&nbsp;</td><td>&nbsp;</td></tr>";
		foreach($obj->start->dates as $rowID => $row) {

			$closes = isset($row->closes) ? $row->closes : '-';
			$opens = isset($row->opens) ? $row->opens : '-';

			$rows[] = "<tr><td><span class='bold'>{$row->term}</span></td><td><span class='bold'>{$closes}</span></td><td><span class='bold'>{$opens}</span></td></tr>";

		}
		$rows[] = "<tr class='section_header'><td class='red'><span class='bold'>{$obj->end->label}</span></td><td>&nbsp;</td><td>&nbsp;</td></tr>";
		foreach($obj->end->dates as $rowID => $row) {

			$lastClass = ($rowID + 1) >= $lastRow ? ' class="end"' : '';

			$closes = isset($row->closes) ? $row->closes : '-';
			$opens = isset($row->opens) ? $row->opens : '-';

			$rows[] = "<tr{$lastClass}><td><span class='bold'>{$row->term}</span></td><td><span class='bold'>{$closes}</span></td><td><span class='bold'>{$opens}</span></td></tr>";

		}
		$rows[] = "</table>";
		$tables[] = implode("\n", $rows);

		$first_tab = false;

	}

	$school_dates['tabs'] = implode("\n\t\t\t\t\t", $tabs);
	$school_dates['tables'] = implode("\n\t\t\t\t\t", $tables);

}


// EVENTS CALENDAR
$events_calendar = array('tabs' => '', 'tables' => '');
if(isset($pageElements->events_calendar) && is_array($pageElements->events_calendar)) {

	$tabs = array();
	$tables = array();
	$first_tab = true;

	foreach($pageElements->events_calendar as $tabID => $obj) {

		if(isset($obj->events) && is_array($obj->events) && $obj->events) {

			$ref = 's' . ($tabID + 1);
			$current = $first_tab ? ' current' : '';
			$hide = $first_tab ? '' : ' hide';

			$tabs[] = "<div class='season{$current} {$ref}'><h3>{$obj->tab}</h3></div>";

			$lastDate = 0;
			$lastMonth = '';
			$lastRow = count($obj->events);
			$alt = true;
			$rows = array();
			$rows[] = "<table class='data {$ref}{$hide}'><tr class='start blue'><th class='fifth'><span class='bold'>Date</span></th><th class='fifth'><span class='bold'>Time</span></th><th><span class='bold'>Event</span></th></tr>";
			foreach($obj->events as $rowID => $row) {

				$date = $row->date;
				$month = date('F', $date);

				if($month != $lastMonth) {

					$rows[] = "<tr class='section_header'><td class='red'><span class='bold'>{$month}</span></td><td>&nbsp;</td><td>&nbsp;</td></tr>";
					$alt = true;
					$lastMonth = $month;

				}

				if($date != $lastDate) {

					$displayDate = date('jS - l', $date);
					$alt = !$alt;
					$lastDate = $date;

				} else {

					$displayDate = '&nbsp;';

				}

				$altClass = $alt ? ' alt' : '';
				$lastClass = ($rowID + 1) >= $lastRow ? ' end' : '';
				$classes = trim($altClass . $lastClass);
				$classes = $classes ? " class='$classes'" : '';

				$time = $row->time ? $row->time : '&nbsp;';
				$event = $row->event ? nl2br($row->event, false) : '&nbsp;';

				$rows[] = "<tr{$classes}><td><span class='bold'>{$displayDate}</span></td><td><span class='bold'>{$time}</span></td><td><span class='bold'>{$event}</span></td></tr>";

			}
			$rows[] = "</table>";
			$tables[] = implode("\n", $rows);

			$first_tab = false;

		}

	}

	$events_calendar['tabs'] = implode("\n\t\t\t\t\t", $tabs);
	$events_calendar['tables'] = implode("\n\t\t\t\t\t", $tables);

}


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'School Dates';

$this->pageContent->body = <<<EOF

				<div class="main_content wide">

					<h2>School Dates</h2>

					{$pageElements->main}

					{$school_dates['tabs']}

					<br class="clear">

					{$school_dates['tables']}

					<h2>Events Calendar</h2>

					{$events_calendar['tabs']}

					<br class="clear">

					{$events_calendar['tables']}

				</div>

<script src="{$this->Config->URL->JS}hive.school_dates.js"></script>

EOF;

?>