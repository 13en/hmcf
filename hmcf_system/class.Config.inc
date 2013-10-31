<?php

/**
 * Site-specific configuration class
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */

class Config {

	public
		$URL			= null,
		$PATH			= null,
		$DB				= null,
		$LANG			= null,
		$IMG			= null,
		$PAGES			= null,
		$MAX_LINKS		= 5;

	public function __construct() {

		$this->URL				= new stdClass();
		$this->URL->WEB			= 'http://hivemcr.hivehost.co.uk/';
		$this->URL->IMG			= 'http://hivemcr.hivehost.co.uk/img/';
		$this->URL->JS			= 'http://hivemcr.hivehost.co.uk/js/';
		$this->URL->CSS			= 'http://hivemcr.hivehost.co.uk/css/';
		$this->URL->DOCS		= 'http://hivemcr.hivehost.co.uk/documents/';
		$this->URL->ADMIN		= 'http://hivemcr.hivehost.co.uk/content-control/';


		$this->PATH				= new stdClass();
		$this->PATH->PAGES		= '/home/hivehost/subdirs/hivemcr/hmcf_templates/';
		$this->PATH->IMG		= '/home/hivehost/subdirs/hivemcr/public_html/img/';
		$this->PATH->DOCS		= '/home/hivehost/subdirs/hivemcr/public_html/documents/';


		$this->DB				= new stdClass();
		$this->DB->HOST			= 'localhost';
		$this->DB->NAME			= 'hivehost_hivemcr';
		$this->DB->USER			= 'hivehost_hivemcr';
		$this->DB->PASS			= 'aMB$zd%rgV=G';


		$this->EMAIL			= new stdClass();
		$this->EMAIL->TO		= 'info@hivemanchester.co.uk';
		$this->EMAIL->FROM		= 'no-reply@hivemanchester.co.uk';


		$this->LANG							= new stdClass();
		$this->LANG->SITE_NAME				= 'Hive Manchester';


		$this->ALLOWED						= new stdClass();
			$this->ALLOWED->DOC				= new stdClass();
				$this->ALLOWED->DOC			= array('pdf', 'doc', 'docx', 'odf');
			$this->ALLOWED->IMG				= new stdClass();
				$this->ALLOWED->IMG			= array('jpg');


		$this->IMG							= new stdClass();
			$this->IMG->home				= new stdClass();
				$this->IMG->home->x			= 1600;
				$this->IMG->home->minx		= 1600;
				$this->IMG->home->maxx		= 2000;
				$this->IMG->home->y			= 960;
				$this->IMG->home->miny		= 960;
				$this->IMG->home->maxy		= 1200;
				$this->IMG->home->ratio		= '5:3';
				$this->IMG->home->dir		= 'home/';
				$this->IMG->home->prefix	= 'bg-';
				$this->IMG->home->quant		= 5;
			$this->IMG->top					= new stdClass();
				$this->IMG->top->x			= 1600;
				$this->IMG->top->minx		= 1600;
				$this->IMG->top->maxx		= 2000;
				$this->IMG->top->y			= 600;
				$this->IMG->top->miny		= 600;
				$this->IMG->top->maxy		= 750;
				$this->IMG->top->ratio		= '8:3';
				$this->IMG->top->dir		= 'top/';
				$this->IMG->top->prefix		= null;
				$this->IMG->top->quant		= 1;
			$this->IMG->side				= new stdClass();
				$this->IMG->side->x			= 209;
				$this->IMG->side->minx		= 209;
				$this->IMG->side->maxx		= 209;
				$this->IMG->side->y			= 209;
				$this->IMG->side->miny		= 209;
				$this->IMG->side->maxy		= 209;
				$this->IMG->side->ratio		= '1:1';
				$this->IMG->side->dir		= null;
				$this->IMG->side->prefix	= null;
				$this->IMG->side->quant		= 1;


		$this->PERMISSIONS					= new stdClass();
		$this->PERMISSIONS->MNG_CLASSES		= 1;
		$this->PERMISSIONS->MNG_ALL			= 2;


	}

}