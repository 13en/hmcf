window.hive = window.hive || {};

$(function () {

	(function () {	// navigation sub menu

		function on() {

			var $testEl = $(this).parent('.cell').length > 0 ? $(this).parent('.cell') : $(this);

			switch(true) {
				
				case $testEl.hasClass('pg_pa'):

					$('#core_full nav .sub').css('display', 'none');
					$('#core_full nav .sub.pg_pa').css('display', 'block');
					break;
				
				case $testEl.hasClass('pg_cl'):

					$('#core_full nav .sub').css('display', 'none');
					$('#core_full nav .sub.pg_cl').css('display', 'block');
					break;

				default:
					$('#core_full nav .sub').css('display', 'none');

			}
		
		}

		function off() {

			$('#core_full nav .sub').css('display', '');
		
		}

		$('#core_full nav .top .cell a, #core_full nav .sub').hover(on, off);

	})();


//	Mobile alerts popup
	$('#core_full footer .links .ma a').click(function () {
		window.open(HMCF_CONFIG.WEBROOT + 'mobile-alerts/', 'mobilePop', 'width=620, height=580, scrollbars=yes');
		return false;
	});


});

$.fn.pulsate = function() {

	function pulse () {

		$(this).delay(1000).fadeOut().delay(500).fadeIn(pulse);

	}
	pulse.call(this);
	return this;

};