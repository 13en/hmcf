<?php

/**
 * Base database class
 *
 * @package		HiveMCR Content Factory
 * @author		Ben Donoghue <ben@hivemanchester.co.uk>
 * @version		0.1
 */
abstract class HMCFData {

	private
		$host = null,
		$name = null,
		$user = null,
		$pass = null;

	protected
		$connection = null;


	public function __construct($config) {

		if(isset($config->HOST, $config->NAME, $config->USER, $config->PASS)) {

			$this->host = $config->HOST;
			$this->name = $config->NAME;
			$this->user = $config->USER;
			$this->pass = $config->PASS;

		}

	}


	protected function connect() {

		if($this->connection) {

			return true;

		} else {

			try {

				$this->connection = new PDO('mysql:dbname=' . $this->name . ';host=' . $this->host, $this->user, $this->pass);
				return true;

			} catch (PDOException $e) {

//				echo 'Connection failed: ' . $e->getMessage();
				$this->connection = null;
				return false;

			}

		}

	}


	public function getPageContent($page) {

		if($this->connect()) {

			$page = $this->connection->quote(md5($page));
			$sth = $this->connection->prepare("SELECT content FROM pages WHERE page = $page");
			$sth->execute();

			$result = $sth->fetch(PDO::FETCH_ASSOC);

			if(isset($result['content'])) {

				$content = json_decode($result['content']);
				return $content;

			}

		}

		return null;

	}


	public function getUsers() {

		if($this->connect()) {

			$sth = $this->connection->prepare("SELECT un, name, permissions FROM users");
			$sth->execute();

			$result = $sth->fetchAll(PDO::FETCH_ASSOC);

			if(isset($result[0]['un'])) {

				return $result;

			}

		}

		return null;

	}


	public function updatePageContent($page, $content) {

		if($this->connect()) {

			$sth = $this->connection->prepare('UPDATE pages SET content = :content WHERE page = :page');
			return $sth->execute(array(':page' => $page, ':content' => $content));

		}

		return false;

	}


	public function addPageContent($page, $content) {

		if($this->connect()) {

			$sth = $this->connection->prepare('INSERT INTO pages (page, content) VALUES (:page, :content)');
			return $sth->execute(array(':page' => $page, ':content' => $content));

		}

		return false;

	}


	public function loginGetUser($un, $pw) {

		if($this->connect()) {

			$un = $this->connection->quote($un);
			$pw = $this->connection->quote(md5($pw));
			$sth = $this->connection->prepare("SELECT un, name, permissions FROM users WHERE un = $un AND pw = $pw");
			$sth->execute();

			$result = $sth->fetch(PDO::FETCH_ASSOC);

			if(isset($result['un'])) {

				return $result;

			}

		}

		return null;

	}


	public function updatePassword($un, $pw) {

		if($this->connect()) {

			$un = $this->connection->quote($un);
			$pw = $this->connection->quote(md5($pw));
			$sth = $this->connection->prepare("UPDATE users SET pw = $pw WHERE un = $un");
			return $sth->execute();

		}

		return false;

	}

}

?>