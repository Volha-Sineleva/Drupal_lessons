(function($){
  /**
  * Attaches training6TextareaAndButton behavior to tables.
  *
  * @type {Drupal~behavior}
  *
  * @prop {Drupal~behaviorAttach} attach
  *   Replaces magic-button value with magic-textarea input text
  *   on every click on magic-textarea.
  */
  Drupal.behaviors.training6TextareaAndButton = {
    attach : function (context) {
      $('#magical_textarea').click(function () {
        var textarea = $('#magical_textarea')[0];
        var button = $('#magical_button')[0];
        button.value = Drupal.checkPlain(textarea.value);
      });
    }
  };
})(jQuery)
