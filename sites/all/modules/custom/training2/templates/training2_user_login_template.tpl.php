<?php

/**
 * @file
 * Displays a page element (list)
 *
 * Available variables:
 * - $title: List title.
 * - $links: Links array.
 * - $items: Array of links' names.
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
