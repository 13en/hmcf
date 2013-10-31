<?php


// SET VARIABLES
$this->pageContent->h1 = 'Ooops!';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					<h2>Sorry, the page you requested could not be found</h2>

					<p class="subheading">The page might have been removed, had its name changed, or is temporarily unavailable.</p>

					<p>Tips:</p>
					<ul>
						<li>Make sure that the URL displayed in the address bar is spelled correctly.</li>
						<li>Use the links at the top and bottom of this page to get back onto the main site.</li>
						<li><a href="{$this->Config->URL->WEB}">Start again, back at our homepage</a></li>
						<li>As a last resort, try searching for the page using a search engine.</li>
					</ul>

				</div>

EOF;

?>