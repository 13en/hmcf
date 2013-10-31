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
	<!--[if lt IE 9]>
	<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->
	<script src="<?php echo $Config->URL->JS; ?>jquery-1.9.1.min.js"></script>
	<script src="<?php echo $Config->URL->JS; ?>hive.js"></script>
	<script>var HMCF_CONFIG = { WEBROOT:'<?php echo $Config->URL->WEB; ?>' };</script>
	<!--[if lte IE 8]><link rel="stylesheet" media="all" href="<?php echo $Config->URL->CSS; ?>ieold.css"><![endif]-->
	<link rel="stylesheet" media="all" href="<?php echo $Config->URL->CSS; ?>core.css">
</head>
<body id="page_<?php echo $HMCF->pageID; ?>" class="parent_<?php echo $HMCF->parentPageID; ?>">

<div id="core_full">

	<header>

		<div class="blank"></div>
		<div class="vbar"></div>
		<div class="hbar"></div>
		<div id="core_strap"><span class="hide">Christ The King RC Primary School - To Work Is To Pray</span></div>

	</header>


	<nav>

		<div class="top">
			<div class="top_inner">
				<div class="cell pg_hm<?php echo $HMCF->parentPageID == 'home' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>">Home</a></div>
				<div class="cell pg_pa<?php echo $HMCF->parentPageID == 'parents' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/">Parents</a></div>
				<div class="cell pg_st<?php echo $HMCF->parentPageID == 'staff' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>staff/">Staff</a></div>
				<div class="cell pg_ne<?php echo $HMCF->parentPageID == 'news' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>news/">News</a></div>
				<div class="cell pg_sd<?php echo $HMCF->parentPageID == 'school-dates' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>school-dates/">School Dates</a></div>
				<div class="cell pg_pta<?php echo $HMCF->parentPageID == 'pta' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>pta/">PTA</a></div>
				<div class="cell pg_li<?php echo $HMCF->parentPageID == 'links' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>links/">Links</a></div>
				<div class="cell pg_cl<?php echo $HMCF->parentPageID == 'classes' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/">Classes</a></div>
				<div class="cell pg_co<?php echo $HMCF->parentPageID == 'contact' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>contact/">Contact</a></div>
			</div>
		</div>
		<div class="sub pg_pa<?php echo $HMCF->parentPageID == 'parents' ? ' active' : ''; ?>">
			<div class="sub_inner">
				<div class="cell pg_pa_ms<?php echo $HMCF->pageID == 'parents__mission_statement' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/mission-statement/">Mission Statement</a></div>
				<div class="cell pg_pa_ad<?php echo $HMCF->pageID == 'parents__admissions' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/admissions/">Admissions</a></div>
				<div class="cell pg_pa_cu<?php echo $HMCF->pageID == 'parents__curriculum' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/curriculum/">Curriculum</a></div>
				<div class="cell pg_pa_un<?php echo $HMCF->pageID == 'parents__uniform' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/uniform/">Uniform</a></div>
				<div class="cell pg_pa_po<?php echo $HMCF->pageID == 'parents__policies_and_documents' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/policies-and-documents/">Policies &amp; Documents</a></div>
				<div class="cell pg_pa_ma<?php echo $HMCF->pageID == 'parents__mailings' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>parents/mailings/">Mailings</a></div>
			</div>
		</div>
		<div class="sub pg_cl<?php echo $HMCF->parentPageID == 'classes' ? ' active' : ''; ?>">
			<div class="sub_inner">
				<div class="cell pg_cl_nursery<?php echo $HMCF->pageID == 'classes__nursery' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/nursery/">Nursery</a></div>
				<div class="cell pg_cl_reception<?php echo $HMCF->pageID == 'classes__reception' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/reception/">Reception</a></div>
				<div class="cell pg_cl_y1<?php echo $HMCF->pageID == 'classes__y1' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y1/">Y1</a></div>
				<div class="cell pg_cl_y2<?php echo $HMCF->pageID == 'classes__y2' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y2/">Y2</a></div>
				<div class="cell pg_cl_y3<?php echo $HMCF->pageID == 'classes__y3' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y3/">Y3</a></div>
				<div class="cell pg_cl_y4<?php echo $HMCF->pageID == 'classes__y4' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y4/">Y4</a></div>
				<div class="cell pg_cl_y5<?php echo $HMCF->pageID == 'classes__y5' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y5/">Y5</a></div>
				<div class="cell pg_cl_y6<?php echo $HMCF->pageID == 'classes__y6' ? ' active' : ''; ?>"><a href="<?php echo $Config->URL->WEB; ?>classes/y6/">Y6</a></div>
			</div>
		</div>

	</nav>


	<div id="core_logo"><a href="<?php echo $Config->URL->WEB; ?>"><span class="hide">Christ The King RC Primary School home</span></a></div>


	<h1><?php $HMCF->echoPageElement('h1'); ?></h1>


	<section id="core_content">

		<div class="full_content">

			<?php
			$preFold = $HMCF->getPageElement('preFold');
			echo $preFold ? "<div class=\"prefold\">\n{$preFold}</div>" : "<div class=\"noprefold\"></div>";
			?>

			<div class="postfold">
				<?php $HMCF->echoPageElement('body'); ?>
				<?php $HMCF->echoPageElement('subContent'); ?>

			</div>

		</div>

		<div class="vbar"></div>
		<?php $HMCF->echoPageElement('alert'); ?>

	</section>


	<footer>

		<div class="address">Christ The King RC Primary School<br>Holly Avenue<br>Walkden, Worsley<br>Manchester M28 3DW</div>
		<div class="contact">Tel: 0161 790 4329<br>Fax: 0161 799 0497<br>Email:<br><a href="mailto:christtheking.rcprimaryschool@salford.gov.uk">christtheking.rcprimaryschool@salford.gov.uk</a></div>

		<div class="links">

			<div class="lp"><a href="http://www.klp.rm.com" target="_blank" class="icon-link">Login to<br>Learning Platform<span class="external-icon"></span></a></div>
			<div class="ma"><a href="<?php echo $Config->URL->WEB; ?>mobile-alerts/" target="_blank" class="icon-link">Sign up for<br>Mobile Alerts<span class="internal-icon"></span></a></div>
			<div class="cw"><a href="http://www.ctkchurch-walkden.org" target="_blank" class="icon-link">Visit Church<br>Website<span class="external-icon"></span></a> <a href="http://www.ctkchurch-walkden.org" target="_blank" class="church-link"><span class="hide">Visit Church Website</span></a></div>

			<div class="cr">&copy; 2013 Christ The King RC Primary School</div>
			<div class="lk"><a href="<?php echo $Config->URL->WEB; ?>terms/">Terms</a> | <a href="<?php echo $Config->URL->WEB; ?>site-map/">Site map</a> | <a href="http://www.hivemanchester.co.uk" target="_blank">Site by Hive</a></div>

		</div>
		<div class="clear"></div>

	</footer>

</div><!-- #core_full -->

<?php $HMCF->echoPageElement('foot'); ?>

</body>
</html>