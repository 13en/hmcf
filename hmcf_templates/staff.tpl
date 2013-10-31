<?php


// STAFF
define('CELLS_PER_ROW', 3);

$staffTitles = array('school_heads', 'section_heads', 'support', 'welfare', 'office', 'site', 'governors');
$staffTables = array_fill_keys($staffTitles, '');

foreach($staffTables as $tableID => $noop) {

	if(isset($pageElements->staff->{$tableID}) && is_array($pageElements->staff->{$tableID})) {

		$arr_staff = array_chunk($pageElements->staff->{$tableID}, CELLS_PER_ROW);

		$is_first_row = true;
		$is_last_row = true;
		$is_first_cell = true;
		$is_second_cell = true;

		$arrRows = array();
		$numRows = count($arr_staff);

		foreach($arr_staff as $rowID => $staffrow) {

			$empty = new stdClass();
			$staffrow = array_pad($staffrow, CELLS_PER_ROW, $empty);

			$is_last_row = ($rowID + 1) >= $numRows;

			$arrCols = array();
			foreach($staffrow as $cellID => $staffcol) {

				$third = $cellID < 2 && $is_first_row ? 'third' : '';
				$end = isset($arr_staff[$rowID + 1][$cellID]->n) || $is_last_row ? '' : 'end';

				if(isset($staffcol->n)) {

					$class = trim("{$third} {$end}");
					$class = $class ? " class='{$class}'" : '';

					if(isset($staffcol->p)) {

						$arrCols[] = "\t\t<td{$class}><span class='bold'>{$staffcol->n}</span><br>{$staffcol->p}</td>";

					} else {

						$arrCols[] = "\t\t<td{$class}><span class='bold'>{$staffcol->n}</span><br>&nbsp;</td>";

					}

				} else {

					$class = trim("{$third} {$end} empty");
					$class = $class ? " class='{$class}'" : '';

					$arrCols[] = "\t\t<td{$class}>&nbsp;</td>";

				}

			}

			$class = trim(($is_first_row ? 'start' : '') . " " . ($is_last_row ? 'end' : ''));
			$class = $class ? " class='{$class}'" : '';

			$arrRows[] = "\t<tr{$class}>\n" . implode("\n", $arrCols) . "\n\t</tr>";

			$is_first_row = false;

		}

		$staffTables[$tableID] = $arrRows ? "<table class='data'>\n" . implode("\n", $arrRows) . "\n</table>" : '';

	}

}


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Staff';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

				<div class="main_content wide">

					{$staffTables['school_heads']}

					<br>

					{$staffTables['section_heads']}

					<h2>Support Staff</h2>

					{$staffTables['support']}

					<h2>Welfare Staff</h2>

					{$staffTables['welfare']}

					<h2>Office Staff</h2>

					{$staffTables['office']}

					<h2>Site Officer</h2>

					{$staffTables['site']}

				</div>

				<div class="main_content">

					<h2>Pastoral Care</h2>

					{$pageElements->pastoral_care}

				</div>

				<div class="main_content wide">

					<h2>School Governors</h2>

					{$staffTables['governors']}

				</div>

EOF;

?>