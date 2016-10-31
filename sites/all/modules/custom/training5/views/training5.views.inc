<?php

/**
 * Implements hook_views_data().
 */
function training5_views_data() {
  $data['training5_exchange_rates']['table']['group'] = t('ExchRatesTable');
  $data['training5_exchange_rates']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Training5 ExchRates'),
    'help' => t('The table contains exchange rates.'),
  );
  $data['training5_exchange_rates']['table']['join'] = array(
    'training5_exchange_rates' => array(
      'left_field' => 'id',
      'field' => 'id',
    ),
  );
  $data['training5_exchange_rates']['id'] = array(
    'title' => t('ID'),
    'help' => t('ID in current table'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'training5_exchange_rates',
      'base field' => 'id',
      'handler' => 'veiws handler relationship',
      'label' => t('Default label for the relationship'),
      'title' => t('Adding relationship title'),
      'help' => t('More additional info'),
    ),
  );
  $data['training5_exchange_rates']['code'] = array(
    'title' => t('Code'),
    'help' => t('Currency code'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['training5_exchange_rates']['rate'] = array(
    'title' => t('Rate'),
    'help' => t('Currency rate'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  return $data;
}
