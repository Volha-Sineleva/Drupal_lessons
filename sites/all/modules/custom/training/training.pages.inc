<?php

/**
 * Page callback for training_menu(),
 * called from $menu['menu']
 *
 * @return string
 */
function training_display_page(){
  return t('This is the landing page of the Training module');
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/custom_access']
 *
 * @return string
 */
function training_access_page(){
  return t('This is page to hook_permission (custom access training)');
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/permissioned']
 *
 * @return string
 */
function training_permissioned_page(){
  return t('This is page to hook_permission (permissioned access training)');
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/callback']
 *
 * @return string
 */
function training_callback_page(){
  return t('The menu entry for this page is of type MENU_CALLBACK');
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/tabs'], $menu['menu/tabs/default']
 *
 * @return string
 */
function training_tab_page(){
  return t('This is the "tabs" menu entry');
}

/**
 * Page callback for training_menu(),
 * called from all the $menu['menu/tabs/*'], exept $menu['menu/tabs/default']
 *
 * @param $tnum
 *  The tab number
 * @param int $level
 *  Level of tag: menu ($level=0) of menu/default ($level=1)
 * @return string
 */
function training_tab_num_page($tnum, $level = 0){
  $leveltest = $level == 0 ? '"basic tabs"' : '"default tabs"';
  $res = 'This is the tab "' . $tnum . '" in the ' . $leveltest . 'example';
  return $res;
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/arguments/%/%']
 *
 * @param $one
 * @param $two
 * @return string
 */
function training_arguments_page ($one, $two) {
  return 'Argument 1 = <em>' . $one . '<em><br>' .
    'Argument 2 = <em>' . $two . '<em>';
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/placeholder/%/display']
 *
 * @param $smth
 *  Any value user enters instead of % in menu/placeholder/%/display
 * @return mixed
 */
function training_placeholder_page($smth){
  return $smth;
}

/**
 * Page callback for training_menu(),
 * called from $menu['menu/default_arg/%']
 *
 * @param $arg
 *  Any value user enters instead of % in menu/default_arg/%
 * @return string
 */
function training_default_arg_page($arg){
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
 * Title callback for training_menu(),
 * called from $menu['menu/title']
 * displays for logged user - user name, for not logged - anonymouse
 *
 * @return string
 */

function training_title_title(){
  global $user;
  if (user_is_logged_in()){
    $username = $user->name;
  }
  else {
    $username = t('anonymouse');
  }

  return t('Dynamic title: username = ') . $username;
}


function training_title_page(){
  global $user;
  if (user_is_logged_in()){
    print_r('USER IS LOGGED ');
    $username = $user->name;
  }
  else {
    print_r('USER IS NOT LOGGED');
    $username = 'anonymouse';
  }
}
/**
 * Page callback for training_menu(),
 * called from $menu['theme'], $menu['theme/link']
 *
 * @param string $atr
 *  parameter to  specify
 * @return string
 */
function training_theme_page($atr = 'parent'){
  $links = array(
    'List' => 'theme/list',
    'Table' => 'theme/table',
    'Image' => 'theme/image',
    'Access' => 'theme/access',
  );
  foreach ($links as $name => &$link){
    $link = l($name,$link);
  }

  return theme('training_theme',array(
    'title' => 'Links to themes',
    'links' => $links,
  ));
}

/**
 * Page callback for training_menu(),
 * called from $menu['theme/table']
 *
 * @return string
 */
function training_theme_table_page(){
  $title = '<h1' .
    drupal_attributes(array('id' => 'table-test')) .
    '>Theme table sample<br>';
  $header = array ('header 1','header 2', 'header 3');
  $rows=array(
    array(
      'data'=> array(
        '11',
        array('data' => '12','colspan' => 2),
      ),
      'class' => array('rowClass')),
    array(
      'data' => array('21','22','23'),
      'class' => array('rowClass')
    ),
    array(
      'data' => array('21','22','23'),
      'class' => array('rowClass')
    ),
  );
  return $title . theme('table',[
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'table-test'),
  ]);
}

/**
 * Page callback for training_menu(),
 * called from $menu['theme/image']
 *
 * @return string
 */
function training_theme_image_page(){
  $path =  drupal_get_path('module', 'training') . '/image/sample.png';
  $image_styles = image_styles();
  $keys = array_keys($image_styles);

  foreach ($image_styles as $i => $style){
    $styles_with_images[] = '<li>' . $style['label'] . '</li>'
      . theme('image_style',array(
        'style_name' => $i,
        'path' => $path,
      ));
  }

  $style_list_title = '<h3>' . t('Available styles for image:') . '</h3>' .
    '<ul>' . implode($styles_with_images) . '</ul>';

  return theme('image',array(
    'path'=> $path,
    'width' => '50%',
    'attributes'=> array('class'=>'simple-image',),
  )) . $style_list_title;
}

/**
 * Page callback for training_menu(),
 * called from $menu['theme/access']
 *
 * @return string
 */
function training_theme_access_page(){
  $access = t('Custom access for rendered content');
  $no_access = t('Custom access inversed for rendered content');
  if (user_access('custom_access_training')){
    return $access;
  }
  else {
    return $no_access;
  }
}
