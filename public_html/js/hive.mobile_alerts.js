var $num = 3;

function addChild()
{
	var $new_child = $('#child_details2').clone();

	$new_child.attr('id', 'child_details'+$num);
	$($new_child.children()[0]).attr('for', 'child'+$num);
	$($new_child.children()[1]).attr('id', 'child'+$num).attr('name', 'child'+$num).val('');
	$($new_child.children()[4]).attr('for', 'class'+$num);
	$($new_child.children()[5]).attr('id', 'class'+$num).attr('name', 'class'+$num).val('');

	$new_child.insertAfter($('#child_details'+($num-1)));

	$num++;
}

$('#add').click(addChild);
