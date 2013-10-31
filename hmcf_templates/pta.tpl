<?php


// PTA
define('CELLS_PER_ROW', 3);

$ptaTitles = array('members', 'representatives');
$ptaTables = array_fill_keys($ptaTitles, '');

foreach($ptaTables as $tableID => $noop) {

	if(isset($pageElements->pta->{$tableID}) && is_array($pageElements->pta->{$tableID})) {

		$arr_pta = array_chunk($pageElements->pta->{$tableID}, CELLS_PER_ROW);

		$is_first_row = true;
		$is_last_row = true;
		$is_first_cell = true;
		$is_second_cell = true;

		$arrRows = array();
		$numRows = count($arr_pta);

		foreach($arr_pta as $rowID => $ptarow) {

			$empty = new stdClass();
			$ptarow = array_pad($ptarow, CELLS_PER_ROW, $empty);

			$is_last_row = ($rowID + 1) >= $numRows;

			$arrCols = array();
			foreach($ptarow as $cellID => $ptacol) {

				$third = $cellID < 2 && $is_first_row ? 'third' : '';
				$end = isset($arr_pta[$rowID + 1][$cellID]->n) || $is_last_row ? '' : 'end';

				if(isset($ptacol->n)) {

					$class = trim("{$third} {$end}");
					$class = $class ? " class='{$class}'" : '';

					if(isset($ptacol->p)) {

						$arrCols[] = "\t\t<td{$class}><span class='bold'>{$ptacol->n}</span><br>{$ptacol->p}</td>";

					} else {

						$arrCols[] = "\t\t<td{$class}><span class='bold'>{$ptacol->n}</span><br>&nbsp;</td>";

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

		$ptaTables[$tableID] = $arrRows ? "<table class='data'>\n" . implode("\n", $arrRows) . "\n</table>" : '';

	}

}


require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'PTA';

$this->pageContent->preFold = <<<EOF

				<div class="bg_img"></div>

				{$quote}

EOF;

$this->pageContent->body = <<<EOF

				<div class="main_content">

					{$pageElements->main}

				</div>

				<div class="main_content wide">

					{$ptaTables['members']}

					<h3>Class Representatives</h3>

					{$ptaTables['representatives']}

				</div>

EOF;

$this->pageContent->subContent = <<<EOF

				<div class="sub_content">

					{$links}

				</div>
EOF;

?>