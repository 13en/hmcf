<?php

/**
 * Extends base class to add in admin functionality
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
class HMCFAdmin extends HMCFBase {


	public function logOut() {

		unset($_SESSION['HMCFA_un']);
		unset($_SESSION['HMCFA_name']);
		unset($_SESSION['HMCFA_perm']);

		$redir = $_SERVER['HTTP_REFERER'];
		$redir = $redir ? $redir : $this->Config->URL->ADMIN;

		header('Location: ' . $redir);
		exit;

	}


	public function logIn() {

		if(isset($_POST['un'], $_POST['pw'])) {

			$user = $this->Data->loginGetUser($_POST['un'], $_POST['pw']);
			if($user) {

				$_SESSION['HMCFA_un'] = $user['un'];
				$_SESSION['HMCFA_name'] = $user['name'];
				$_SESSION['HMCFA_perm'] = $user['permissions'];

			} else {

				$_SESSION['logerr'] = true;

			}
			$redir = $_SERVER['HTTP_REFERER'];
			$redir = $redir ? $redir : $this->Config->URL->ADMIN;

		}

		header('Location: ' . $redir);
		exit;

	}


	protected function isLogged() {

		if(isset($_SESSION['HMCFA_un'], $_SESSION['HMCFA_name'], $_SESSION['HMCFA_perm'])) {

			$this->user_un = $_SESSION['HMCFA_un'];
			$this->user_name = $_SESSION['HMCFA_name'];
			$this->user_perm = $_SESSION['HMCFA_perm'];

			return true;

		} else {

			return false;

		}

	}


	protected function hasPermission($permission) {

		if(isset($this->Config->PERMISSIONS->$permission)) {

			return $this->user_perm & $this->Config->PERMISSIONS->$permission;

		} else {

			return false;

		}

	}


	protected function saveUsers() {

		$saved = false;

		if(isset($_POST['un'], $_POST['pw']) && is_array($_POST['un']) && is_array($_POST['pw']) && count($_POST['un']) == count($_POST['pw'])) {

			foreach($_POST['un'] as $key => $val) {

				$pw = trim($_POST['pw'][$key]);
				if($pw) {

					$saved = $this->Data->updatePassword($_POST['un'][$key], $pw);
					if(!$saved) break;

				} else {

					$saved = true;

				}

			}

		}

		$_SESSION['updated'] = $saved;

		return $this->Config->URL->ADMIN;

	}


	protected function permissionHalt($permission) {

		if(!$this->hasPermission($permission)) {

			$bt = debug_backtrace();
			$line = isset($bt[0]['line']) ? $bt[0]['line'] : '000';

			exit('Ooops! It looks like you don\'t have permission to look at this. Please contact the administrator, quoting \'e' . $line . '\', if you feel this is wrong.');

		}

		return true;

	}


	protected function imgUpload($config) {

		$msg = 'Image could not be uploaded';

		if(isset($config->newFile, $config->dimensions)) {

			$newFile = $config->newFile;
			$dimensions = $config->dimensions;
			$fieldName = isset($config->fieldName) ? $config->fieldName : 'fullimage';

			$allowedMimes = array('image/jpeg', 'image/pjpeg');

			if($_FILES[$fieldName]['error'] == UPLOAD_ERR_OK && in_array($_FILES[$fieldName]['type'], $allowedMimes)) {

				if(move_uploaded_file($_FILES[$fieldName]['tmp_name'], $newFile)) {

					list($width, $height) = getimagesize($newFile);
					if($width < $dimensions->minx || $height < $dimensions->miny) {

						// too small - throw away
						$msg = 'Selected image is too small';
						@unlink($newFile);

					} elseif($width > $dimensions->maxx) {

						// too large - resize to max permitted
						$newWidth = $dimensions->maxx;
						$ratio = $width / $newWidth;
						$newHeight = round($height / $ratio);

						$image = imagecreatetruecolor($newWidth, $newHeight);
						$source = imagecreatefromjpeg($newFile);

						imagecopyresampled($image, $source, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
						if(imagejpeg($image, $newFile, 100)) {
							$msg = '';
							chmod($newFile, 0777);
						} else {
							@unlink($newFile);
						}
						imagedestroy($image);

					} else {

						// close enough - keep and cherish
						$msg = '';

					}

				} else {

					@unlink($newFile);

				}

			}

		}

		return $msg;

	}


	protected function cropImage($config) {

		$newWidth = ceil($config->w * $config->scale);
		$newHeight = ceil($config->h * $config->scale);

		$image = imagecreatetruecolor($newWidth, $newHeight);
		$source = imagecreatefromjpeg($config->srcFile);

		imagecopyresampled($image, $source, 0, 0, $config->x1, $config->y1, $newWidth, $newHeight, $config->w, $config->h);
		$success = imagejpeg($image, $config->dstFile, 100);
		imagedestroy($image);
		chmod($config->dstFile, 0777);

		if($success) {

			@unlink($config->srcFile);

		}

		return $success;

	}


	private function calculateDimensions($endWidth, $endHeight, $width, $height) {

		$return = array('width' => $width, 'height' => $height);

		if((($width / $height) > ($endWidth / $endHeight)) && ($width > $endWidth)) {

			$return['width'] = $endWidth;
			$return['height'] = $endWidth / $width * $height;

		} elseif($height > $endHeight) {

			$return['width'] = $endHeight / $height * $width;
			$return['height'] = $endHeight;

		}

		return $return;

	}


	protected function updatePage() {

		$saved = false;

		//get current data
		$pageContent = $this->Data->getPageContent($this->pageID);

		if(isset($pageContent->updated)) {

			$pageContent->updated = time();

			$saved = $this->Data->updatePageContent(md5($this->pageID), json_encode($pageContent));

		}

		return $saved;

	}


}

?>