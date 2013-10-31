<?php

require_once '../hmcf_system/initialise.inc';

$Config = new Config();

$HMCF = new HMCF();
$HMCF->output();

?>
<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<title><?php $HMCF->echoPageElement('h1'); echo ' | ' . $Config->LANG->SITE_NAME; ?></title>
	<script src="<?php echo $Config->URL->JS; ?>jquery-1.9.1.min.js"></script>
	<link rel="stylesheet" media="all" href="<?php echo $Config->URL->CSS; ?>pop.css">
</head>
<body>

	<div id="logo_bar">

		<div id="logo"></div>

	</div>

	<div id="content">

		<h1><?php $HMCF->echoPageElement('h1'); ?></h1>

		<?php $HMCF->echoPageElement('body'); ?>

	</div>

<?php $HMCF->echoPageElement('foot'); ?>

</body>
</html>