<?php

require_once($this->Config->PATH->PAGES . 'general.common.tpl');


// SET VARIABLES
$this->pageContent->h1 = 'Contact';

$this->pageContent->body = <<<EOF

				<div class="main_content">

					<h2>Contact Us</h2>
					<p class="subheading">Please contact the school using the details below:</p>

					<iframe width="500" height="300" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.co.uk/maps?oe=utf-8&amp;client=firefox-a&amp;q=M28+3DW&amp;ie=UTF8&amp;hq=&amp;hnear=Worsley+M28+3DW,+United+Kingdom&amp;gl=uk&amp;t=m&amp;ll=53.52684,-2.390385&amp;spn=0.015307,0.04283&amp;z=14&amp;iwloc=lyrftr:m,14478660825280149970,53.52108,-2.390739&amp;output=embed"></iframe><br /><small><a href="https://maps.google.co.uk/maps?oe=utf-8&amp;client=firefox-a&amp;q=M28+3DW&amp;ie=UTF8&amp;hq=&amp;hnear=Worsley+M28+3DW,+United+Kingdom&amp;gl=uk&amp;t=m&amp;ll=53.52684,-2.390385&amp;spn=0.015307,0.04283&amp;z=14&amp;iwloc=lyrftr:m,14478660825280149970,53.52108,-2.390739&amp;source=embed" style="color:#0000FF;text-align:left">View Larger Map</a></small>

					{$pageElements->main}

				</div>

EOF;

$this->pageContent->subContent = <<<EOF

				<div class="sub_content">

					{$links}

				</div>
EOF;

?>