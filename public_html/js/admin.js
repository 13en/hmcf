window.hive = window.hive || {};
(function () {

	hive.imgPreload = function (a) {
		$(a).each(function () {
			$('<img/>')[0].src = this;
		});
	};

	hive.imageCrop = function (config) {

		function updateCoords() {

			if(typeof(arguments[1]) == 'object') {

				$('#x1Fld').val(arguments[1].x1);
				$('#y1Fld').val(arguments[1].y1);
				$('#x2Fld').val(arguments[1].x2);
				$('#y2Fld').val(arguments[1].y2);
				$('#wFld').val(arguments[1].width);
				$('#hFld').val(arguments[1].height);

			}

		}

		$('img#largeImg').imgAreaSelect({
			handles: true,
			minWidth: config.width,
			minHeight: config.height,
			aspectRatio: config.ratio,
			x1: $('#x1Fld').val(),
			y1: $('#y1Fld').val(),
			x2: $('#x2Fld').val(),
			y2: $('#y2Fld').val(),
			onSelectEnd: updateCoords
		});

	};

	hive.reorderer = function (config) {

		function up() {

			var par = $(this).parents(el);
			par.insertBefore(par.prev(el));
			return false;

		}

		function down() {

			var par = $(this).parents(el);
			par.insertAfter(par.next(el));
			return false;

		}

		var el = '';

		if(typeof(config.up) == 'string') {

			$(config.up).click(up);

		}
		if(typeof(config.down) == 'string') {

			$(config.down).click(down);

		}
		if(typeof(config.el) == 'string') {

			el = config.el;

		}

	};

	hive.listControl = function () {

		function del() {

			var par = $(this).parents('.control .row');

			if(par.hasClass('deleted')) {

				par.removeClass('deleted');
				par.find('input[type=text], input[type=checkbox], input[type=hidden], textarea, select').removeAttr('disabled');
				par.find('input[type=hidden].invertdisable').attr('disabled', 'disabled');
				par.find('input.deleteFld').val('0');

			} else {

				par.addClass('deleted');
				par.find('input[type=text], input[type=checkbox], input[type=hidden], textarea, select').attr('disabled', 'disabled');
				par.find('input[type=hidden].invertdisable').removeAttr('disabled');
				par.find('input.deleteFld').val('1');

			}
				
			return false;

		}

		function up() {

			var par = $(this).parents('.control .row');
			removeEditor();
			par.insertBefore(par.prev('.control .row'));
			initEditor();
			return false;

		}

		function down() {

			var par = $(this).parents('.control .row');
			removeEditor();
			par.insertAfter(par.next('.control .row'));
			initEditor();
			return false;

		}

		function removeEditor() {

			var start = tinyEditors.length - 1;
			for(var i=start; i>=0; i--) {
				tinyMCE.execCommand('mceRemoveControl', false, tinyEditors[i]); 
			};

		}

		function initEditor() {

			var start = tinyEditors.length - 1;
			for(var i=start; i>=0; i--) {
				tinymce.execCommand('mceAddControl', false, tinyEditors[i]); 
			};

		}

		var tinyEditors = [];
		setTimeout(function () {
			
			var start = tinymce.editors.length - 1;
			for(var i=start; i>=0; i--) {
				tinyEditors.push(tinymce.editors[i].id); 
			};

		}, 1000);

		$('.control .delete').click(del);
		$('.control .up').click(up);
		$('.control .down').click(down);

	};

	hive.selectLinks = function (linkIDs) {

		var $allSelects = $('#links select');

		$allSelects.each(function () {
		
			thisID = linkIDs.shift();
			if(typeof(thisID) == 'string') {

				$(this).val(thisID);

			}

		});

	};

})();