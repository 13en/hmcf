<?php

$this->pageContent->h1 = 'Site Map';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					<h2>Site Map</h2>

					<ul class="top">
						<li><a href="{$this->Config->URL->WEB}">Home</a></li>
						<li><a href="{$this->Config->URL->WEB}parents/">Parents</a>
							<ul>
								<li><a href="{$this->Config->URL->WEB}parents/mission-statement/">Mission Statement</a></li>
								<li><a href="{$this->Config->URL->WEB}parents/admissions/">Admissions</a></li>
								<li><a href="{$this->Config->URL->WEB}parents/curriculum/">Curriculum</a></li>
								<li><a href="{$this->Config->URL->WEB}parents/uniform/">Uniform</a></li>
								<li><a href="{$this->Config->URL->WEB}parents/policies-and-documents/">Policies &amp; Documents</a></li>
								<li><a href="{$this->Config->URL->WEB}parents/mailings/">Mailings</a></li>
							</ul>
						</li>
						<li><a href="{$this->Config->URL->WEB}staff/">Staff</a></li>
						<li><a href="{$this->Config->URL->WEB}news/">News</a></li>
						<li><a href="{$this->Config->URL->WEB}school-dates/">School Dates</a></li>
						<li><a href="{$this->Config->URL->WEB}pta/">PTA</a></li>
						<li><a href="{$this->Config->URL->WEB}links/">Links</a></li>
						<li><a href="{$this->Config->URL->WEB}classes/">Classes</a>
							<ul>
								<li><a href="{$this->Config->URL->WEB}classes/nursery/">Nursery</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/reception/">Reception</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y1/">Y1</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y2/">Y2</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y3/">Y3</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y4/">Y4</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y5/">Y5</a></li>
								<li><a href="{$this->Config->URL->WEB}classes/y6/">Y6</a></li>
							</ul>
						</li>
						<li><a href="{$this->Config->URL->WEB}contact/">Contact</a></li>
						<li><a href="{$this->Config->URL->WEB}terms/">Terms</a></li>
					</ul>

				</div>

EOF;

?>