<?php

if(isset($_GET['e']) && is_array($_GET['e'])) {

	$errors = array();
	foreach($_GET['e'] as $err) {

		$errors[] = "<li>{$err}</li>";

	}
	$message = '<p class="error">Please ensure each field is correctly completed:</p><ul class="error">' . implode("\n", $errors) . '</ul>';

} elseif(isset($_GET['sent'])) {

	$message = '<p class="success">Thank you for providing this information. We will update your details as required. You can now close this window.</p>';

} else {

	$message = '';

}

// SET VARIABLES
$this->pageContent->h1 = 'Mobile alerts and emails form';

$this->pageContent->body = <<<EOF

		<h2>Improving links with school</h2>

		<p>We know that letters home are not always the most reliable way of sending you information and that is why we have decided to implement a text messaging and e-mail service.</p>

		<p>This will enable you to receive all your information from school quickly and reliably. We can send letters by email to your inbox and short messages directly to your mobile phone as a text message. Just fill in the fields below and submit.</p>

		{$message}

		<form action="{$this->Config->URL->WEB}do-mobile-alerts/" method="post">

			<label for="name" class="bold">Your name: </label><input id="name" type="text" name="name" class="right"><br><br>

			<label for="mobile" class="bold">Mobile number: </label><input id="mobile" type="text" name="mobile" class="right"><br><br>

			<span class="right"><input id="new_num" type="checkbox" name="new_num" value="1"><label for="new_num" class="bold">Please tick if this is a new number</label></span><br><br>

			<label for="email" class="bold">e-mail address: </label><input id="email" type="text" name="email" class="right"><br><br>

			<div id="child_details1">
				<label for="child1" class="bold">Name of child: </label><input id="child1" type="text" name="child1" class="right"><br><br>
				<label for="class1" class="bold">Class: </label><input id="class1" type="text" name="class1" class="right"><br><br><br>
			</div>

			<div id="child_details2">
				<label for="child2" class="bold">Name of child: </label><input id="child2" type="text" name="child2" class="right"><br><br>
				<label for="class2" class="bold">Class: </label><input id="class2" type="text" name="class2" class="right"><br><br><br>
			</div>

			<input id="add" type="button" name="add" value="Add another child" class="bold"><br><br>

			<input id="agreement" type="checkbox" name="agreement" value="1">
			<div id="agree"><label for="agreement">I agree for the school to hold my personal details on their database for school business purposes. Please tick.</label></div>

			<input id="submit" class="bold" type="submit" value="Submit">

		</form>

EOF;

$this->pageContent->foot = <<<EOF

<script src="{$this->Config->URL->JS}hive.mobile_alerts.js" type="text/javascript"></script>

EOF;

?>