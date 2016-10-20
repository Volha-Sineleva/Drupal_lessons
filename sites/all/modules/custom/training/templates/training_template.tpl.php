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

<ul><strong><?php echo $title ?></strong>

<?php
  $list = '';
  foreach ($links as $link){
    $list .= '<li>' . $link . '</li>';
  }
  $list .= '</ul>';

  print ($list);
