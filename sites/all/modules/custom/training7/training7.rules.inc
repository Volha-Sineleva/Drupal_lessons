<?php

/**
 * Implements hook_rules_event_info().
 */
function training7_rules_event_info() {
  $items = array(
    'training7_user_visited_lottery' => array(
      'label' => t('User has visited lottery page'),
      'group' => t('Training7'),
      'access callback' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_rules_condition_info().
 */
function training7_rules_condition_info() {
  $items = array(
    'training7_lottery_result' => array(
      'label' => t('Lottery is won'),
      'group' => t('Training7'),
    ),
  );
  return $items;
}

/**
 * Implements hook_rules_action_info().
 */
function training7_rules_action_info() {
  $items = array(
    'training7_show_lottery_win_message' => array(
      'label' => t('Display a lottery win message'),
      'group' => t('Training7'),
      'access callback' => TRUE,
    ),
  );
  return $items;
}

/**
 * Callback function for rule condition.
 *
 * Generates random number and sends it by xmlprc to get lottery result(bool).
 * Stores in cache data for Lottery Table block.
 */
function training7_lottery_result() {

  $rand = rand(1, 8);
  global $base_url;
  $server = url($base_url . '/xmlrpc.php', array('external' => TRUE));
  $options = array(
    'training7_lottery_run.generate' => array($rand),
  );
  $lottery_code = xmlrpc($server, $options);
  if ($lottery_code === FALSE) {
    drupal_set_message(
      t('Error return from xmlrpc(): Error: @errno, Message: @message',
        array('@errno' => xmlrpc_errno(), '@message' => xmlrpc_error_msg())),
      'error'
    );
  }

  $lottery_id = cache_get('current_lottery_id');
  $lottery_id = $lottery_id? $lottery_id->data : 0;
  $data = cache_get('lottery_list');
  $data = $data ? $data->data : array();

  $lottery_id++;
  global $user;
  $data[] = array(
    'lottery_ID' => $lottery_id,
    'user_ID' => $user->uid,
    'time' => format_date(REQUEST_TIME, 'custom', 'd.m.Y H:i:s'),
    'result' => $lottery_code,
  );
  cache_set('lottery_list', $data);
  cache_set('current_lottery_id', $lottery_id);

  return $lottery_code === TRAINING7_LOTTERY_WIN_CODE;
}

/**
 * Callback function for rule action.
 */
function training7_show_lottery_win_message() {

  $msg = t("Dear [user:name]! Congratulations! You are the winner of our lottery!
    Your lucky lottery #[lottery:id] was run on [lottery:time].");

  global $user;
  $id = cache_get('current_lottery_id');
  $lottery = (object) array(
    'id' => $id->data,
    'time' => format_date(REQUEST_TIME, 'long'),
  );
  $needed_data = array('user' => $user, 'lottery' => $lottery);
  $result = token_replace($msg, $needed_data);
  cache_set($user->uid . '_is_winner', $result);

  drupal_set_message($result);
}
