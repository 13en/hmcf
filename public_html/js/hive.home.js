(function () {

	(function () {	// background, quote and button changer

		function scroll() {

			try {

				var newID = parseInt($(this).parents('li').attr('id').replace('bullet', ''));
				if(isNaN(newID)) throw new RangeError('Unexpected button press. What have you done, butterfingers?!');

				if(newID == currID) return false;

				clearInterval(tmr);
				
				// set button
				$('section#core_content .full_content .home-quotes li').removeClass('active');
				$('section#core_content .full_content .home-quotes li#bullet' + newID).addClass('active');

				// set quote
				$('section#core_content .full_content .home-quotes .quotes div').fadeOut(FADE_INTERVAL);
				$('section#core_content .full_content .home-quotes .quotes .id' + newID).fadeIn(FADE_INTERVAL);

				// set background
				$('section#core_content .full_content .bg_imgs div').fadeOut(FADE_INTERVAL);
				$('section#core_content .full_content .bg_imgs .id' + newID).fadeIn(FADE_INTERVAL);

				// set currID AND THEN new timer after fading is finished
				tmr = setTimeout(function () {
					
					currID = newID;
					tmr = setTimeout(next, SCROLL_INTERVAL);

				}, FADE_INTERVAL);

			} catch(e) {

				alert(e.message);

			} finally {

				return false;

			}

		}

		function next() {

			var $currEl = $('.full_content .home-quotes li.active'),
				$nextEl = $currEl.next();

			$nextEl = $nextEl.length ? $nextEl : $('.full_content .home-quotes li:first-child');

			$nextEl.children('a').click();

		}

		var tmr = null,
			currID = 1,
			maxID = 5,
			SCROLL_INTERVAL = 4000,
			FADE_INTERVAL = 1000;

		tmr = setTimeout(next, SCROLL_INTERVAL);

		$('section#core_content .full_content .bg_imgs div:first-child, section#core_content .full_content .home-quotes .quotes div:first-child').fadeIn(FADE_INTERVAL);
		$('.full_content .home-quotes li:first-child').addClass('active');
		maxID = $('.full_content .home-quotes li a').click(scroll).length;

	})();

})();