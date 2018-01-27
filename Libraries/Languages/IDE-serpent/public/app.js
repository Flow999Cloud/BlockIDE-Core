$(document).ready(function () {
  $('#compile').on('click', function () {
    $.get('/compile/serpent', {
      code: $('#serpent').val()
    }, function (result) {
      if (result.data) {
        return $('#result').val(result.data);
      } else if (result.message) {
        return $('#result').val(result.message);
      }
    });
  });
});