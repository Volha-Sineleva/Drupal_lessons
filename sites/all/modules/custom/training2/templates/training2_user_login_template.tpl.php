<?php

/**
 * @file
 * Displays an altered user-login form
 *
 * Available variables:
 * - $form: array.
 */
?>

<table>
  <tr>
    <td>
      <?php print(drupal_render($form['name'])); ?>
    </td>
  </tr>
  <tr>
    <td>
      <?php print(drupal_render($form['pass'])); ?>
    </td>
  </tr>
  <tr>
    <td>
      <?php print(drupal_render($form['secret_key'])); ?>
    </td>
  </tr>
</table>

<?php print(drupal_render_children($form)); ?>
