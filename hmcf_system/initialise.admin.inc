<?php


/**
 * Extends HMCFAdmin class to add in site-specific admin functionality
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
class Admin extends HMCFAdmin {

	public
		$pageID = 'default',
		$pagePath = 'default',
		$user_un = null,
		$user_name = null,
		$user_perm = null,
		$content = '';


	public function output() {

		if($this->isLogged()) {

			if(isset($_GET['ht_homeimg'])) {

				$this->displayHomeImagePage();

			} elseif(isset($_GET['ht_topimg'])) {

				$this->displayTopImagePage();

			} else {

				$this->content = new stdClass();
				$this->displayPage();

			}

		} else {

			require_once($this->Config->PATH->PAGES . 'admin/login.tpl');

		}

	}


	private function displayPage() {

		$template_file = null;

		if($this->pageID == 'home') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Home';
			$template_file = $this->Config->PATH->PAGES . 'admin/home.tpl';

		} elseif($this->pageID == 'parents') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Parents';
			$template_file = $this->Config->PATH->PAGES . 'admin/parents.tpl';

		} elseif($this->pageID == 'parents__mission_statement') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Mission statement';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'parents__admissions') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Admissions';
			$template_file = $this->Config->PATH->PAGES . 'admin/main-links.tpl';

		} elseif($this->pageID == 'parents__curriculum') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Curriculum';
			$template_file = $this->Config->PATH->PAGES . 'admin/main-links.tpl';

		} elseif($this->pageID == 'parents__uniform') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Uniform';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'parents__policies_and_documents') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Policies &amp; documents';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main-pdocs.tpl';

		} elseif($this->pageID == 'parents__mailings') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Mailings';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main-pdocs.tpl';

		} elseif($this->pageID == 'staff') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Staff';
			$template_file = $this->Config->PATH->PAGES . 'admin/staff.tpl';

		} elseif($this->pageID == 'news') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'News';
			$template_file = $this->Config->PATH->PAGES . 'admin/news.tpl';

		} elseif($this->pageID == 'school_dates') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'School dates';
			$template_file = $this->Config->PATH->PAGES . 'admin/school-dates.tpl';

		} elseif($this->pageID == 'pta') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'PTA';
			$template_file = $this->Config->PATH->PAGES . 'admin/pta.tpl';

		} elseif($this->pageID == 'links') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Links';
			$template_file = $this->Config->PATH->PAGES . 'admin/main-plinks.tpl';

		} elseif($this->pageID == 'classes') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Classes';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__reception') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Reception';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__nursery') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Nursery';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y1') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 1';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y2') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 2';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y3') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 3';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y4') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 4';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y5') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 5';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'classes__y6') {

			$this->permissionHalt('MNG_CLASSES');
			$pageName = 'Year 6';
			$template_file = $this->Config->PATH->PAGES . 'admin/topimage-quote-main.tpl';

		} elseif($this->pageID == 'contact') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Contact';
			$template_file = $this->Config->PATH->PAGES . 'admin/main-links.tpl';

		} elseif($this->pageID == 'terms') {

			$this->permissionHalt('MNG_ALL');
			$pageName = 'Terms';
			$template_file = $this->Config->PATH->PAGES . 'admin/main-links.tpl';

		} elseif($this->pageID == 'users') {

			$this->permissionHalt('MNG_ALL');
			$arrUsers = $this->Data->getUsers();
			$pageName = 'Control Panel Users';
			$template_file = $this->Config->PATH->PAGES . 'admin/users.tpl';

		}

		if(isset($template_file)) {

			$pageContent = $this->Data->getPageContent($this->pageID);

			if(isset($pageContent->updated)) {

				$this->updateID = dechex($pageContent->updated);

			} else {

				$this->updateID = '';

			}

		} else {

			$template_file = $this->Config->PATH->PAGES . 'admin/default.tpl';

		}

		require_once($template_file);

	}


	private function displayHomeImagePage() {

		$pageName = 'Home';
		$imageObj = $this->Config->IMG->home;
		$imageID = intval($_GET['ht_homeimg']);

		require_once($this->Config->PATH->PAGES . 'admin/image.home.tpl');

	}


	private function displayTopImagePage() {

		$pageName = 'Top';
		$imageObj = $this->Config->IMG->top;

		require_once($this->Config->PATH->PAGES . 'admin/image.top.tpl');

	}


	public function submit() {

		if($this->isLogged()) {

			$goto = $this->Config->URL->ADMIN;

			switch($this->pageID) {

				case 'users':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveUsers();
					break;


				case 'home':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveHome();
					break;


				case 'parents':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveParents();
					break;


				case 'parents__mission_statement':
				case 'parents__uniform':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveTopimageQuoteMain();
					break;


				case 'classes':
				case 'classes__reception':
				case 'classes__nursery':
				case 'classes__y1':
				case 'classes__y2':
				case 'classes__y3':
				case 'classes__y4':
				case 'classes__y5':
				case 'classes__y6':
					$this->permissionHalt('MNG_CLASSES');
					$goto = $this->saveTopimageQuoteMain();
					break;


				case 'parents__admissions':
				case 'parents__curriculum':
				case 'contact':
				case 'terms':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveMainLinks();
					break;


				case 'parents__policies_and_documents':
				case 'parents__mailings':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveTopimageQuoteMainPdocs();
					break;


				case 'links':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveMainPlinks();
					break;


				case 'staff':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveStaff();
					break;


				case 'pta':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->savePta();
					break;


				case 'news':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveNews();
					break;


				case 'school_dates':
					$this->permissionHalt('MNG_ALL');
					$goto = $this->saveSchoolDates();
					break;


				default:
					echo 'E:' . __LINE__;exit;

			}

		}

		header("Location: {$goto}");
		exit;

	}


	protected function saveHome() {

		$saved = false;

		if(isset($_POST['quote'], $_POST['cite'], $_POST['alert']) && is_array($_POST['quote']) && is_array($_POST['cite']) && count($_POST['quote']) == count($_POST['cite'])) {

			if(isset($_POST['homeimg_delete']) && is_array($_POST['homeimg_delete'])) {

				foreach($_POST['homeimg_delete'] as $id) {

					$id = intval($id);
					@unlink($this->Config->PATH->IMG . $this->Config->IMG->home->dir . $this->Config->IMG->home->prefix . $id . '.jpg');

				}

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$quotes = array();
			foreach($_POST['quote'] as $key => $val) {

				$quote = new stdClass();
				$quote->q = stripslashes($_POST['quote'][$key]);
				$quote->c = stripslashes($_POST['cite'][$key]);
				if(!$quote->c)
					unset($quote->c);

				$quotes[] = $quote;

			}
			$pageContent->quotes = $quotes;

			$pageContent->alert = stripslashes($_POST['alert']);

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveParents() {

		$saved = false;
		$msg = false;

		if(isset($_POST['quote'], $_POST['cite'], $_POST['welcome'], $_POST['infant_hours_r1'], $_POST['infant_hours_r2'], $_POST['infant_hours_r3'], $_POST['junior_hours_r1'], $_POST['junior_hours_r2'], $_POST['junior_hours_r3'], $_POST['main'], $_POST['headteacher'])) {

			if(isset($_POST['topimg_delete']) && $_POST['topimg_delete']) {

				@unlink($this->Config->PATH->IMG . $this->Config->IMG->top->dir . $this->pageID . '.jpg');

			}

			if(isset($_POST['headteacherimg_delete']) && $_POST['headteacherimg_delete']) {

				@unlink($this->Config->PATH->IMG . $this->pageID . '/headteacher.jpg');

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->quote = new stdClass();
			$pageContent->quote->q = stripslashes($_POST['quote']);
			$pageContent->quote->c = stripslashes($_POST['cite']);
			if(!$pageContent->quote->c)
				unset($pageContent->quote->c);

			$pageContent->welcome = stripslashes($_POST['welcome']);

			$pageContent->infant_hours = new stdClass();
			$pageContent->infant_hours->r1 = stripslashes($_POST['infant_hours_r1']);
			$pageContent->infant_hours->r2 = stripslashes($_POST['infant_hours_r2']);
			$pageContent->infant_hours->r3 = stripslashes($_POST['infant_hours_r3']);

			$pageContent->junior_hours = new stdClass();
			$pageContent->junior_hours->r1 = stripslashes($_POST['junior_hours_r1']);
			$pageContent->junior_hours->r2 = stripslashes($_POST['junior_hours_r2']);
			$pageContent->junior_hours->r3 = stripslashes($_POST['junior_hours_r3']);

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->headteacher = stripslashes($_POST['headteacher']);

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

			if($_FILES['headteacherimg']['size']) {

				$config = new stdClass();

				$config->newFile = $this->Config->PATH->IMG . $this->pageID . '/headteacher.jpg';
				$config->dimensions = $this->Config->IMG->side;
				$config->fieldName = 'headteacherimg';

				$msg = $this->imgUpload($config);

			}

		}

		if(strlen($msg))	$_SESSION['saveerr'] = $msg;
		else				$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveTopimageQuoteMain() {

		$saved = false;

		if(isset($_POST['quote'], $_POST['cite'], $_POST['main'])) {

			if(isset($_POST['topimg_delete']) && $_POST['topimg_delete']) {

				@unlink($this->Config->PATH->IMG . $this->Config->IMG->top->dir . $this->pageID . '.jpg');

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->quote = new stdClass();
			$pageContent->quote->q = stripslashes($_POST['quote']);
			$pageContent->quote->c = stripslashes($_POST['cite']);
			if(!$pageContent->quote->c)
				unset($pageContent->quote->c);

			$pageContent->main = stripslashes($_POST['main']);

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveTopimageQuoteMainPdocs() {

		$saved = false;

		if(isset($_POST['quote'], $_POST['cite'], $_POST['main'], $_POST['add_pdocs_title'], $_FILES['add_pdocs_file_file'])) {

			if(isset($_POST['topimg_delete']) && $_POST['topimg_delete']) {

				@unlink($this->Config->PATH->IMG . $this->Config->IMG->top->dir . $this->pageID . '.jpg');

			}

			// remove files from deleted pdocs
			if(isset($_POST['pdocs_file_delete']) && is_array($_POST['pdocs_file_delete'])) {

				foreach($_POST['pdocs_file_delete'] as $remove) {

					@unlink($this->Config->PATH->DOCS . $this->pagePath . '/' . $remove);

				}

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->quote = new stdClass();
			$pageContent->quote->q = stripslashes($_POST['quote']);
			$pageContent->quote->c = stripslashes($_POST['cite']);
			if(!$pageContent->quote->c)
				unset($pageContent->quote->c);

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->pdocs = array();
			if(isset($_POST['pdocs_title'], $_POST['pdocs_file']) && is_array($_POST['pdocs_title']) && is_array($_POST['pdocs_file']) && count($_POST['pdocs_title']) == count($_POST['pdocs_file'])) {

				foreach($_POST['pdocs_title'] as $idx => $obj) {

					$link = new stdClass();
					$link->title = stripslashes($_POST['pdocs_title'][$idx]);
					$link->file = trim($_POST['pdocs_file'][$idx]);

					$pageContent->pdocs[] = $link;

				}

			}
			if($_POST['add_pdocs_title'] && $_FILES['add_pdocs_file_file']['size']) {

				$filename = strtolower(trim($_FILES['add_pdocs_file_file']['name']));
				$parts = pathinfo($filename);
				$ext = $parts['extension'];

				if(in_array($ext, $this->Config->ALLOWED->DOC)) {

					if(!is_dir($this->Config->PATH->DOCS . $this->pagePath . '/')) mkdir($this->Config->PATH->DOCS . $this->pagePath . '/');

					$name = md5(date('YmdHis'));

					$filename = $name . '.' . $ext;
					$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
					$counter = 1;

					while(file_exists($newFilePath)) {

						$filename = $name . '-' . $counter . '.' . $ext;
						$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
						$counter++;

					}

					if(move_uploaded_file($_FILES['add_pdocs_file_file']['tmp_name'], $newFilePath)) {

						$link = new stdClass();
						$link->title = stripslashes($_POST['add_pdocs_title']);
						$link->file = $filename;

						$pageContent->pdocs[] = $link;

					}

				}

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveMainLinks() {

		$saved = false;

		if(isset($_POST['main'], $_POST['add_links_type'], $_POST['add_links_title']) && (isset($_POST['add_links_file_text']) || isset($_FILES['add_links_file_file']))) {

			// remove files from deleted links
			if(isset($_POST['links_file_delete']) && is_array($_POST['links_file_delete'])) {

				foreach($_POST['links_file_delete'] as $remove) {

					@unlink($this->Config->PATH->DOCS . $this->pagePath . '/' . $remove);

				}

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->links = array();
			if(isset($_POST['links_type'], $_POST['links_title'], $_POST['links_file']) && is_array($_POST['links_type']) && is_array($_POST['links_title']) && is_array($_POST['links_file']) && count($_POST['links_type']) == count($_POST['links_title']) && count($_POST['links_type']) == count($_POST['links_file'])) {

				foreach($_POST['links_type'] as $idx => $obj) {

					if(in_array($_POST['links_type'][$idx], array('internal', 'external', 'download'))) {

						$link = new stdClass();
						$link->type = $_POST['links_type'][$idx];
						$link->title = stripslashes($_POST['links_title'][$idx]);
						$link->file = trim($_POST['links_file'][$idx]);

						$pageContent->links[] = $link;

					}

				}

			}
			if(isset($_POST['add_links_file_text']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_POST['add_links_file_text']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$link = new stdClass();
					$link->type = $_POST['add_links_type'];
					$link->title = stripslashes($_POST['add_links_title']);
					$link->file = trim($_POST['add_links_file_text']);

					$pageContent->links[] = $link;

				}

			} elseif(isset($_FILES['add_links_file_file']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_FILES['add_links_file_file']['size']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$filename = strtolower(trim($_FILES['add_links_file_file']['name']));
					$parts = pathinfo($filename);
					$ext = $parts['extension'];

					if(in_array($ext, $this->Config->ALLOWED->DOC)) {

						if(!is_dir($this->Config->PATH->DOCS . $this->pagePath . '/')) mkdir($this->Config->PATH->DOCS . $this->pagePath . '/');

						$name = md5(date('YmdHis'));

						$filename = $name . '.' . $ext;
						$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
						$counter = 1;

						while(file_exists($newFilePath)) {

							$filename = $name . '-' . $counter . '.' . $ext;
							$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
							$counter++;

						}

						if(move_uploaded_file($_FILES['add_links_file_file']['tmp_name'], $newFilePath)) {

							$link = new stdClass();
							$link->type = $_POST['add_links_type'];
							$link->title = stripslashes($_POST['add_links_title']);
							$link->file = $filename;

							$pageContent->links[] = $link;

						}

					}

				}

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveNews() {

		$saved = false;

		if(isset($_POST['add_news_title'], $_POST['add_news_author'], $_POST['add_news_main'], $_FILES['add_news_image'], $_POST['add_links_type'], $_POST['add_links_title']) && (isset($_POST['add_links_file_text']) || isset($_FILES['add_links_file_file']))) {

			// remove images from deleted news
			if(isset($_POST['news_image_delete']) && is_array($_POST['news_image_delete'])) {

				foreach($_POST['news_image_delete'] as $remove) {

					@unlink($this->Config->PATH->IMG . $this->pagePath . '/' . $remove);

				}

			}

			// remove files from deleted links
			if(isset($_POST['links_file_delete']) && is_array($_POST['links_file_delete'])) {

				foreach($_POST['links_file_delete'] as $remove) {

					@unlink($this->Config->PATH->DOCS . $this->pagePath . '/' . $remove);

				}

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->news = array();
			if(isset($_POST['news_title'], $_POST['news_author'], $_POST['news_main'], $_POST['news_image']) && is_array($_POST['news_title']) && is_array($_POST['news_author']) && is_array($_POST['news_main']) && is_array($_POST['news_image']) && count($_POST['news_title']) == count($_POST['news_author']) && count($_POST['news_title']) == count($_POST['news_main']) && count($_POST['news_title']) == count($_POST['news_image'])) {

				foreach($_POST['news_title'] as $idx => $obj) {

					$newsObj = new stdClass();
					$newsObj->title = stripslashes($_POST['news_title'][$idx]);
					$newsObj->author = stripslashes($_POST['news_author'][$idx]);
					$newsObj->main = stripslashes($_POST['news_main'][$idx]);
					$newsObj->image = stripslashes($_POST['news_image'][$idx]);

					$pageContent->news[] = $newsObj;

				}

			}
			if($_POST['add_news_title'] && $_POST['add_news_main']) {

				$newsObj = new stdClass();
				$newsObj->title = stripslashes($_POST['add_news_title']);
				if($_POST['add_news_author'])		$newsObj->author = stripslashes($_POST['add_news_author']);
				$newsObj->main = stripslashes($_POST['add_news_main']);

				if($_FILES['add_news_image']['size']) {

					$name = md5(date('YmdHis'));

					$config = new stdClass();

					$config->newFile = $this->Config->PATH->IMG . $this->pageID . '/' . $name . '.jpg';
					$config->dimensions = $this->Config->IMG->side;
					$config->fieldName = 'add_news_image';

					$msg = $this->imgUpload($config);

					if(strlen($msg) < 2) {

						$newsObj->image = $name . '.jpg';

					}

				}

				$pageContent->news[] = $newsObj;

			}

			$pageContent->links = array();
			if(isset($_POST['links_type'], $_POST['links_title'], $_POST['links_file']) && is_array($_POST['links_type']) && is_array($_POST['links_title']) && is_array($_POST['links_file']) && count($_POST['links_type']) == count($_POST['links_title']) && count($_POST['links_type']) == count($_POST['links_file'])) {

				foreach($_POST['links_type'] as $idx => $obj) {

					if(in_array($_POST['links_type'][$idx], array('internal', 'external', 'download'))) {

						$link = new stdClass();
						$link->type = $_POST['links_type'][$idx];
						$link->title = stripslashes($_POST['links_title'][$idx]);
						$link->file = trim($_POST['links_file'][$idx]);

						$pageContent->links[] = $link;

					}

				}

			}
			if(isset($_POST['add_links_file_text']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_POST['add_links_file_text']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$link = new stdClass();
					$link->type = $_POST['add_links_type'];
					$link->title = stripslashes($_POST['add_links_title']);
					$link->file = trim($_POST['add_links_file_text']);

					$pageContent->links[] = $link;

				}

			} elseif(isset($_FILES['add_links_file_file']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_FILES['add_links_file_file']['size']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$filename = strtolower(trim($_FILES['add_links_file_file']['name']));
					$parts = pathinfo($filename);
					$ext = $parts['extension'];

					if(in_array($ext, $this->Config->ALLOWED->DOC)) {

						if(!is_dir($this->Config->PATH->DOCS . $this->pagePath . '/')) mkdir($this->Config->PATH->DOCS . $this->pagePath . '/');

						$name = md5(date('YmdHis'));

						$filename = $name . '.' . $ext;
						$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
						$counter = 1;

						while(file_exists($newFilePath)) {

							$filename = $name . '-' . $counter . '.' . $ext;
							$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
							$counter++;

						}

						if(move_uploaded_file($_FILES['add_links_file_file']['tmp_name'], $newFilePath)) {

							$link = new stdClass();
							$link->type = $_POST['add_links_type'];
							$link->title = stripslashes($_POST['add_links_title']);
							$link->file = $filename;

							$pageContent->links[] = $link;

						}

					}

				}

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveMainPlinks() {

		$saved = false;

		if(isset($_POST['main'], $_POST['add_plinks_title'], $_POST['add_plinks_file_text'])) {

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->plinks = array();
			if(isset($_POST['plinks_title'], $_POST['plinks_file']) && is_array($_POST['plinks_title']) && is_array($_POST['plinks_file']) && count($_POST['plinks_title']) == count($_POST['plinks_file'])) {

				foreach($_POST['plinks_title'] as $idx => $obj) {

					$plink = new stdClass();
					$plink->title = stripslashes($_POST['plinks_title'][$idx]);
					$plink->file = trim($_POST['plinks_file'][$idx]);

					$pageContent->plinks[] = $plink;

				}

			}
			if($_POST['add_plinks_title'] && $_POST['add_plinks_file_text']) {

				$plink = new stdClass();
				$plink->title = stripslashes($_POST['add_plinks_title']);
				$plink->file = trim($_POST['add_plinks_file_text']);

				$pageContent->plinks[] = $plink;

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveStaff() {

		$saved = false;

		if(isset($_POST['main'], $_POST['add_school_heads_n'], $_POST['add_school_heads_p'], $_POST['add_section_heads_n'], $_POST['add_section_heads_p'], $_POST['add_support_n'], $_POST['add_support_p'], $_POST['add_welfare_n'], $_POST['add_welfare_p'], $_POST['add_office_n'], $_POST['add_office_p'], $_POST['add_site_n'], $_POST['add_site_p'], $_POST['add_governors_n'], $_POST['add_governors_p'], $_POST['pastoral_care'])) {

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->pastoral_care = stripslashes($_POST['pastoral_care']);

			$pageContent->staff = new stdClass();
			$staffTitles = array('school_heads', 'section_heads', 'support', 'welfare', 'office', 'site', 'governors');
			foreach($staffTitles as $staffID) {

				$pageContent->staff->{$staffID} = array();
				if(isset($_POST[$staffID . '_n'], $_POST[$staffID . '_p']) && is_array($_POST[$staffID . '_n']) && is_array($_POST[$staffID . '_p']) && count($_POST[$staffID . '_n']) == count($_POST[$staffID . '_p'])) {

					foreach($_POST[$staffID . '_n'] as $key => $obj) {

						$sObj = new stdClass();
						$sObj->n = stripslashes($_POST[$staffID . '_n'][$key]);
						$sObj->p = stripslashes($_POST[$staffID . '_p'][$key]);
						if(!$sObj->p)
							unset($sObj->p);

						if($sObj->n)
							$pageContent->staff->{$staffID}[] = $sObj;

					}

				}
				if($_POST['add_' . $staffID . '_n']) {

					$sObj = new stdClass();
					$sObj->n = stripslashes($_POST['add_' . $staffID . '_n']);
					$sObj->p = stripslashes($_POST['add_' . $staffID . '_p']);
					if(!$sObj->p)
						unset($sObj->p);

					if($sObj->n)
						$pageContent->staff->{$staffID}[] = $sObj;

				}

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function savePta() {

		$saved = false;

		if(isset($_POST['quote'], $_POST['cite'], $_POST['main'], $_POST['add_members_n'], $_POST['add_members_p'], $_POST['add_representatives_n'], $_POST['add_representatives_p'], $_POST['add_links_type'], $_POST['add_links_title']) && (isset($_POST['add_links_file_text']) || isset($_FILES['add_links_file_file']))) {

			if(isset($_POST['topimg_delete']) && $_POST['topimg_delete']) {

				@unlink($this->Config->PATH->IMG . $this->Config->IMG->top->dir . $this->pageID . '.jpg');

			}

			// remove files from deleted links
			if(isset($_POST['links_file_delete']) && is_array($_POST['links_file_delete'])) {

				foreach($_POST['links_file_delete'] as $remove) {

					@unlink($this->Config->PATH->DOCS . $this->pagePath . '/' . $remove);

				}

			}

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->quote = new stdClass();
			$pageContent->quote->q = stripslashes($_POST['quote']);
			$pageContent->quote->c = stripslashes($_POST['cite']);
			if(!$pageContent->quote->c)
				unset($pageContent->quote->c);

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->pta = new stdClass();
			$ptaTitles = array('members', 'representatives');
			foreach($ptaTitles as $ptaID) {

				$pageContent->pta->{$ptaID} = array();
				if(isset($_POST[$ptaID . '_n'], $_POST[$ptaID . '_p']) && is_array($_POST[$ptaID . '_n']) && is_array($_POST[$ptaID . '_p']) && count($_POST[$ptaID . '_n']) == count($_POST[$ptaID . '_p'])) {

					foreach($_POST[$ptaID . '_n'] as $key => $obj) {

						$sObj = new stdClass();
						$sObj->n = stripslashes($_POST[$ptaID . '_n'][$key]);
						$sObj->p = stripslashes($_POST[$ptaID . '_p'][$key]);
						if(!$sObj->p)
							unset($sObj->p);

						if($sObj->n)
							$pageContent->pta->{$ptaID}[] = $sObj;

					}

				}
				if($_POST['add_' . $ptaID . '_n']) {

					$sObj = new stdClass();
					$sObj->n = stripslashes($_POST['add_' . $ptaID . '_n']);
					$sObj->p = stripslashes($_POST['add_' . $ptaID . '_p']);
					if(!$sObj->p)
						unset($sObj->p);

					if($sObj->n)
						$pageContent->pta->{$ptaID}[] = $sObj;

				}

			}

			$pageContent->links = array();
			if(isset($_POST['links_type'], $_POST['links_title'], $_POST['links_file']) && is_array($_POST['links_type']) && is_array($_POST['links_title']) && is_array($_POST['links_file']) && count($_POST['links_type']) == count($_POST['links_title']) && count($_POST['links_type']) == count($_POST['links_file'])) {

				foreach($_POST['links_type'] as $idx => $obj) {

					if(in_array($_POST['links_type'][$idx], array('internal', 'external', 'download'))) {

						$link = new stdClass();
						$link->type = $_POST['links_type'][$idx];
						$link->title = stripslashes($_POST['links_title'][$idx]);
						$link->file = trim($_POST['links_file'][$idx]);

						$pageContent->links[] = $link;

					}

				}

			}
			if(isset($_POST['add_links_file_text']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_POST['add_links_file_text']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$link = new stdClass();
					$link->type = $_POST['add_links_type'];
					$link->title = stripslashes($_POST['add_links_title']);
					$link->file = trim($_POST['add_links_file_text']);

					$pageContent->links[] = $link;

				}

			} elseif(isset($_FILES['add_links_file_file']) && $_POST['add_links_type'] && $_POST['add_links_title'] && $_FILES['add_links_file_file']['size']) {

				if(in_array($_POST['add_links_type'], array('internal', 'external', 'download'))) {

					$filename = strtolower(trim($_FILES['add_links_file_file']['name']));
					$parts = pathinfo($filename);
					$ext = $parts['extension'];

					if(in_array($ext, $this->Config->ALLOWED->DOC)) {

						if(!is_dir($this->Config->PATH->DOCS . $this->pagePath . '/')) mkdir($this->Config->PATH->DOCS . $this->pagePath . '/');

						$name = md5(date('YmdHis'));

						$filename = $name . '.' . $ext;
						$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
						$counter = 1;

						while(file_exists($newFilePath)) {

							$filename = $name . '-' . $counter . '.' . $ext;
							$newFilePath = $this->Config->PATH->DOCS . $this->pagePath . '/' . $filename;
							$counter++;

						}

						if(move_uploaded_file($_FILES['add_links_file_file']['tmp_name'], $newFilePath)) {

							$link = new stdClass();
							$link->type = $_POST['add_links_type'];
							$link->title = stripslashes($_POST['add_links_title']);
							$link->file = $filename;

							$pageContent->links[] = $link;

						}

					}

				}

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	protected function saveSchoolDates() {

		$saved = false;

		if(isset($_POST['main'], $_POST['dates_1_start_label'], $_POST['add_dates_1_start_term'], $_POST['add_dates_1_start_closes'], $_POST['add_dates_1_start_opens'], $_POST['dates_1_end_label'], $_POST['add_dates_1_end_term'], $_POST['add_dates_1_end_closes'], $_POST['add_dates_1_end_opens'], $_POST['dates_2_start_label'], $_POST['add_dates_2_start_term'], $_POST['add_dates_2_start_closes'], $_POST['add_dates_2_start_opens'], $_POST['dates_2_end_label'], $_POST['add_dates_2_end_term'], $_POST['add_dates_2_end_closes'], $_POST['add_dates_2_end_opens'], $_POST['add_events_autumn_date'], $_POST['add_events_autumn_time'], $_POST['add_events_autumn_event'], $_POST['add_events_spring_date'], $_POST['add_events_spring_time'], $_POST['add_events_spring_event'], $_POST['add_events_summer_date'], $_POST['add_events_summer_time'], $_POST['add_events_summer_event'])) {

			$pageContent = new stdClass();

			$pageContent->updated = time();

			$pageContent->main = stripslashes($_POST['main']);

			$pageContent->school_dates = array();
			$numTabs = 2;
			for($tabNo = 1; $tabNo <= $numTabs; $tabNo++) {

				$dateTab = new stdClass();
				$dateTab->start = new stdClass();
				$dateTab->start->label = intval($_POST['dates_' . $tabNo . '_start_label']);
				$dateTab->start->dates = array();
				if(isset($_POST['dates_' . $tabNo . '_start_term'], $_POST['dates_' . $tabNo . '_start_closes'], $_POST['dates_' . $tabNo . '_start_opens']) && is_array($_POST['dates_' . $tabNo . '_start_term']) && is_array($_POST['dates_' . $tabNo . '_start_closes']) && is_array($_POST['dates_' . $tabNo . '_start_opens']) && count($_POST['dates_' . $tabNo . '_start_term']) == count($_POST['dates_' . $tabNo . '_start_closes']) && count($_POST['dates_' . $tabNo . '_start_term']) == count($_POST['dates_' . $tabNo . '_start_opens'])) {

					foreach($_POST['dates_' . $tabNo . '_start_term'] as $idx => $obj) {

						$dateObj = new stdClass();
						$dateObj->term = stripslashes($_POST['dates_' . $tabNo . '_start_term'][$idx]);
						$dateObj->closes = stripslashes($_POST['dates_' . $tabNo . '_start_closes'][$idx]);
						$dateObj->opens = stripslashes($_POST['dates_' . $tabNo . '_start_opens'][$idx]);

						if(!trim($dateObj->closes)) unset($dateObj->closes);
						if(!trim($dateObj->opens)) unset($dateObj->opens);

						$dateTab->start->dates[] = $dateObj;

					}

				}
				if($_POST['add_dates_' . $tabNo . '_start_term']) {

					$dateObj = new stdClass();
					$dateObj->term = stripslashes($_POST['add_dates_' . $tabNo . '_start_term']);
					$dateObj->closes = stripslashes($_POST['add_dates_' . $tabNo . '_start_closes']);
					$dateObj->opens = stripslashes($_POST['add_dates_' . $tabNo . '_start_opens']);

					if(!trim($dateObj->closes)) unset($dateObj->closes);
					if(!trim($dateObj->opens)) unset($dateObj->opens);

					$dateTab->start->dates[] = $dateObj;

				}

				$dateTab->end = new stdClass();
				$dateTab->end->label = intval($_POST['dates_' . $tabNo . '_end_label']);
				$dateTab->end->dates = array();
				if(isset($_POST['dates_' . $tabNo . '_end_term'], $_POST['dates_' . $tabNo . '_end_closes'], $_POST['dates_' . $tabNo . '_end_opens']) && is_array($_POST['dates_' . $tabNo . '_end_term']) && is_array($_POST['dates_' . $tabNo . '_end_closes']) && is_array($_POST['dates_' . $tabNo . '_end_opens']) && count($_POST['dates_' . $tabNo . '_end_term']) == count($_POST['dates_' . $tabNo . '_end_closes']) && count($_POST['dates_' . $tabNo . '_end_term']) == count($_POST['dates_' . $tabNo . '_end_opens'])) {

					foreach($_POST['dates_' . $tabNo . '_end_term'] as $idx => $obj) {

						$dateObj = new stdClass();
						$dateObj->term = stripslashes($_POST['dates_' . $tabNo . '_end_term'][$idx]);
						$dateObj->closes = stripslashes($_POST['dates_' . $tabNo . '_end_closes'][$idx]);
						$dateObj->opens = stripslashes($_POST['dates_' . $tabNo . '_end_opens'][$idx]);

						if(!trim($dateObj->closes)) unset($dateObj->closes);
						if(!trim($dateObj->opens)) unset($dateObj->opens);

						$dateTab->end->dates[] = $dateObj;

					}

				}
				if($_POST['add_dates_' . $tabNo . '_end_term']) {

					$dateObj = new stdClass();
					$dateObj->term = stripslashes($_POST['add_dates_' . $tabNo . '_end_term']);
					$dateObj->closes = stripslashes($_POST['add_dates_' . $tabNo . '_end_closes']);
					$dateObj->opens = stripslashes($_POST['add_dates_' . $tabNo . '_end_opens']);

					if(!trim($dateObj->closes)) unset($dateObj->closes);
					if(!trim($dateObj->opens)) unset($dateObj->opens);

					$dateTab->end->dates[] = $dateObj;

				}
				if($dateTab->start->dates || $dateTab->end->dates) {

					$pageContent->school_dates[] = $dateTab;

				}

			}

			$pageContent->events_calendar = array();
			$eventsTabs = array('autumn', 'spring', 'summer');
			foreach($eventsTabs as $tab) {

				$tabObj = new stdClass();
				$tabObj->tab = ucfirst($tab);
				$tabObj->events = array();
				if(isset($_POST['events_' . $tab .'_date'], $_POST['events_' . $tab .'_time'], $_POST['events_' . $tab .'_event']) && is_array($_POST['events_' . $tab .'_date']) && is_array($_POST['events_' . $tab .'_time']) && is_array($_POST['events_' . $tab .'_event']) && count($_POST['events_' . $tab .'_date']) == count($_POST['events_' . $tab .'_time']) && count($_POST['events_' . $tab .'_date']) == count($_POST['events_' . $tab .'_event'])) {

					foreach($_POST['events_' . $tab .'_date'] as $idx => $obj) {

						$dateObj = new stdClass();
						$dateObj->date = $_POST['events_' . $tab .'_date'][$idx] / 1000;
						$dateObj->time = stripslashes($_POST['events_' . $tab .'_time'][$idx]);
						$dateObj->event = stripslashes($_POST['events_' . $tab .'_event'][$idx]);

						$tabObj->events[] = $dateObj;

					}

				}

				if($_POST['add_events_' . $tab .'_date'] && $_POST['add_events_' . $tab .'_event']) {

					$dateObj = new stdClass();
					$dateObj->date = $_POST['add_events_' . $tab .'_date'] / 1000;
					$dateObj->time = stripslashes($_POST['add_events_' . $tab .'_time']);
					$dateObj->event = stripslashes($_POST['add_events_' . $tab .'_event']);

					$tabObj->events[] = $dateObj;

				}

				// order events by date
				$reorder = array();
				foreach($tabObj->events as $key => $row) {
					$reorder[$key] = $row->date;
				}
				array_multisort($reorder, SORT_ASC, $tabObj->events);

				$pageContent->events_calendar[] = $tabObj;

			}

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN . $this->pageID . '/';

	}


	public function processHomeImgUpload() {

		$success = false;

		if($this->isLogged()) {

			$imageID = intval($_POST['imageID']);

			$config = new stdClass();

			$config->newFile = $this->Config->PATH->IMG . 'uploads/' . $this->pageID . '-' . $this->Config->IMG->home->prefix . $imageID . '.jpg';
			$config->dimensions = $this->Config->IMG->home;

			$msg = $this->imgUpload($config);

		}

		if(strlen($msg))	$_SESSION['saveerr'] = $msg;
		else				$_SESSION['updated'] = true;

		header('Location: ' . $_SERVER['HTTP_REFERER']);
		exit;

	}


	public function processHomeImgCrop() {

		$success = false;

		if($this->isLogged()) {

			$imgID = intval($_POST['imageID']);

			$config = new stdClass();
			$config->srcFile = $this->Config->PATH->IMG . 'uploads/' . $this->pageID . '-' . $this->Config->IMG->home->prefix . $imgID . '.jpg';
			$config->dstFile = $destDir . $this->Config->IMG->home->prefix . $imgID .'.jpg';
			$config->w = intval($_POST['w']);
			$config->h = intval($_POST['h']);
			$config->x1 = intval($_POST['x1']);
			$config->y1 = intval($_POST['y1']);
			$config->scale = $this->Config->IMG->home->x / $config->w;

			$success = $this->cropImage($config);

			if($success)	$this->updatePage();

		}

		if($success)	$_SESSION['updated'] = true;
		else			$_SESSION['saveerr'] = 'Image could not be cropped';

		header('Location: ' . $this->Config->URL->ADMIN . $this->pageID . '/');
		exit();

	}


	public function processTopImgUpload() {

		$success = false;

		if($this->isLogged()) {

			$config = new stdClass();

			$config->newFile = $this->Config->PATH->IMG . 'uploads/' . $this->pageID . '-bg.jpg';
			$config->dimensions = $this->Config->IMG->top;

			$msg = $this->imgUpload($config);

		}

		if(strlen($msg))	$_SESSION['saveerr'] = $msg;
		else				$_SESSION['updated'] = true;

		header('Location: ' . $_SERVER['HTTP_REFERER']);
		exit;

	}


	public function processTopImgCrop() {

		$success = false;

		if($this->isLogged()) {

			$config = new stdClass();
			$config->srcFile = $this->Config->PATH->IMG . 'uploads/' . $this->pageID . '-bg.jpg';
			$config->dstFile = $this->Config->PATH->IMG . $this->Config->IMG->top->dir . $this->pageID . '.jpg';
			$config->w = intval($_POST['w']);
			$config->h = intval($_POST['h']);
			$config->x1 = intval($_POST['x1']);
			$config->y1 = intval($_POST['y1']);
			$config->scale = $this->Config->IMG->top->x / $config->w;

			$success = $this->cropImage($config);

			if($success)	$this->updatePage();

		}

		if($success)	$_SESSION['updated'] = true;
		else			$_SESSION['saveerr'] = 'Image could not be cropped';

		header('Location: ' . $this->Config->URL->ADMIN . $this->pageID . '/');
		exit();

	}


	private function limitText($text, $limit) {

		if(str_word_count($text, 0) > $limit) {

			$words = str_word_count($text, 2);
			$pos = array_keys($words);
			$text = substr($text, 0, $pos[$limit]) . '...';

		}

		return $text;

	}

}

?>