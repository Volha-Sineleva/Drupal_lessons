<?php

/**
 * Page callback for /menu.
 */
function training_display_page() {
  return t('This is the landing page of the Training module');
}

/**
 * Page callback for menu/custom_access.
 */
function training_access_page() {
  return t('This is page to hook_permission (custom access training)');
}

/**
 * Page callback for menu/permissioned.
 */
function training_permissioned_page() {
  return t('This is page to hook_permission (permissioned access training)');
}

/**
 * Page callback for menu/callback
 */
function training_callback_page() {
  return t('The menu entry for this page is of type MENU_CALLBACK');
}

/**
 * Page callback for menu/tabs and menu/tabs/default
 */
function training_tab_page() {
  return t('This is the "tabs" menu entry');
}

/**
 * Page callback for menu/tabs/*, exept menu/tabs/default
 *
 * @param $tnum
 *  The tab number.
 * @param int $level
 *  Level of tag: menu ($level=0) or menu/default ($level=1).
 */
function training_tab_num_page($tnum, $level = 0) {

  $leveltest = $level == 0 ? t('"basic tabs"') : t('"default tabs"');

  return t('This is the tab "!tnum" in the !leveltest example', array(
    '!tnum' => $tnum,
    '!leveltest' => $leveltest,
  ));
}

/**
 * Page callback for menu/arguments/%/%
 */
function training_arguments_page ($one, $two) {

  return t('Argument 1 = @one,<br> Argument 2 = @two.', array(
    '@one' => $one,
    '@two' => $two,
  ));
}

/**
 * Page callback for menu/placeholder/%/display
 *
 * @param $smth
 *  Any value user enters instead of % in menu/placeholder/%/display
 */
function training_placeholder_page($smth) {
  return check_plain($smth);
}

/**
 * Page callback for menu/default_arg/%
 */
function training_default_arg_page($arg) {

  switch ($arg) {
    case 1:
      $output = 'one';
      break;

    case 2:
      $output = 'two';
      break;

    case 3:
      $output = 'three';
      break;

    case 99:
      $output = 'Almost there';
      break;

    default:
      $output = '404 page is not found';
  }

  return $output;
}

/**
 * Callback for'menu/title.
 * Displays for logged user - user name, for not logged - anonymouse
 */
function training_title_title() {

  global $user;
  $username = user_is_logged_in() ? $user->name : t('anonymouse');

  return t('Dynamic title: username = !username', array('!username' => $username));
}

/**
 * Page callback for theme and theme/link.
 */
function training_theme_page() {

  $links = array(
    'List' => 'theme/list',
    'Table' => 'theme/table',
    'Image' => 'theme/image',
    'Access' => 'theme/access',
  );
  foreach ($links as $name => &$link) {
    $link = l($name, $link);
  }

  return theme('training_theme', array(
    'title' => 'Links to themes',
    'links' => $links,
  ));
}

/**
 * Page callback for theme/table
 */
function training_theme_table_page() {

  $attributes = drupal_attributes(array('id' => 'table-test'));
  $title_text = 'Theme table sample';
  $title = '<h1' . $attributes . '>' . $title_text;

  $header = array('header 1', 'header 2', 'header 3',);
  $rows=array(
    array(
      'data'=> array(
        '11',
        array('data' => '12', 'colspan' => 2),
      ),
      'class' => array('rowClass')),
    array(
      'data' => array('21', '22', '23'),
      'class' => array('rowClass'),
    ),
    array(
      'data' => array('21', '22', '23'),
      'class' => array('rowClass'),
    ),
  );

  return $title . theme('table', [
    'header' => $header,
    'rows' => $rows,
    'attributes' => $attributes,
  ]);
}

/**
 * Page callback for theme/image
 */
function training_theme_image_page() {

  $path =  drupal_get_path('module', 'training') . '/image/sample.png';
  $image_styles = image_styles();
  $keys = array_keys($image_styles);

  foreach ($image_styles as $i => $style) {
    $styles_with_images[] = '<li>' . $style['label'] . '</li>'
      . theme('image_style', array(
        'style_name' => $i,
        'path' => $path,
      ));
  }

  $sl_title = t('Available styles for image:');
  $sl_content = implode($styles_with_images);
  $style_list = "<h3> $sl_title </h3><ul> $sl_content </ul>";

  return theme('image', array(
    'path'=> $path,
    'width' => '50%',
    'attributes'=> array('class'=>'simple-image'),
  )) . $style_list;
}

/**
 * Page callback for theme/access
 */
function training_theme_access_page() {

  $access = t('Custom access for rendered content');
  $no_access = t('Custom access inversed for rendered content');

  return user_access('custom_access_training') ? $access : $no_access;
}
