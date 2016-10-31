/**
 * Attaches training5FilesTable behavior to tables.
 *
 * @type {Drupal~behavior}
 *
 * @prop {Drupal~behaviorAttach} attach
 *   Paints in gold table rows with id = uid-[UserID].
 */
(function($){

  Drupal.behaviors.training5FilesTable = {
    attach : function (context) {
      var rowClass = '.uid-' + Drupal.settings.uid;
      var $rows = $(rowClass);
      $rows = [].slice.call($rows);
      $rows.forEach(function (item, i, arr) {
        item.style.backgroundColor = 'gold';
      });
    }
  };

})(jQuery)
