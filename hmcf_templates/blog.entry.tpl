<?php

//var_dump($pageElements);

$title = $pageElements->title;

$this->pageContent->pageTitle = $title . ' | blog';

$this->pageContent->sidemenu = <<<EOF

<h1>news</h1>
<h2>News and posts</h2>
<p>Here you will find updates on our work, things that interest and inspire us, news and views.</p>
<a id="prev" href="#prev">Previous</a>
<a id="next" href="#next">Next</a>

EOF;

$main = $pageElements->main;
$this->pageContent->mainContent = '<div id="blog-post"><article>' . $main . '</article><a id="back" href="#back">back</a></div>';