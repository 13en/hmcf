function calendar(table) {

	switch(true) {

		case $(this).hasClass('y1'):
			
			if($('table.y1').hasClass('hide'))
			{
				$('table.y2').addClass('hide');
				$('table.y1').removeClass('hide');

				$(this).addClass('current');
				$('.season.y2').removeClass('current');
			}
			break;

		case $(this).hasClass('y2'):

			if($('table.y2').hasClass('hide'))
			{
				$('table.y1').addClass('hide');
				$('table.y2').removeClass('hide');

				$(this).addClass('current');
				$('.season.y1').removeClass('current');
			}
			break;

		case $(this).hasClass('s1'):
			
			if($('table.s1').hasClass('hide'))
			{
				$('table.s2').addClass('hide');
				$('table.s3').addClass('hide');
				$('table.s1').removeClass('hide');

				$(this).addClass('current');
				$('.season.s2').removeClass('current');
				$('.season.s3').removeClass('current');
			}
			break;		
			
		case $(this).hasClass('s2'):
			
			if($('table.s2').hasClass('hide'))
			{
				$('table.s1').addClass('hide');
				$('table.s3').addClass('hide');
				$('table.s2').removeClass('hide');

				$(this).addClass('current');
				$('.season.s1').removeClass('current');
				$('.season.s3').removeClass('current');
			}
			break;		
			
		case $(this).hasClass('s3'):
			
			if($('table.s3').hasClass('hide'))
			{
				$('table.s1').addClass('hide');
				$('table.s2').addClass('hide');
				$('table.s3').removeClass('hide');

				$(this).addClass('current');
				$('.season.s1').removeClass('current');
				$('.season.s2').removeClass('current');
			}
			break;

	}

}

$('.main_content .season').click(calendar);