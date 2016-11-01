<?php

/**
 * Implements hook_token_info().
 */
function training7_token_info() {

  $info['types']['lottery'] = array(
    'name' => t('Lottery'),
    'description' => t('Tokens related to lottery'),
    'needs-data' => 'lottery',
  );
  $info['tokens']['lottery']['id'] = array(
    'name' => t('id'),
    'description' => t('The unique ID of the lottery'),
  );
  $info['tokens']['lottery']['time'] = array(
    'name' => t('time'),
    'description' => t('Date and time of the lottery run'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function training7_tokens($type, $tokens, $data = array()) {

  $replacements = array();
  if ($type == 'lottery' && !empty($data['lottery'])) {
    $lottery = $data['lottery'];
    foreach ($tokens as $name => $token) {
      switch ($name) {
        case 'id':
          $replacements[$token] = $lottery->id;
          break;

        case 'time':
          $replacements[$token] = $lottery->time;
          break;
      }
    }
  }

  return $replacements;
}
