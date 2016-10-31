<?php

/**
 * Implements hook_views_default_views().
 */
function training5_views_default_views() {
  $view = new view();
  $view->name = 'exchange_rates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'training5_exchange_rates';
  $view->human_name = 'Exchange Rates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Exchange Rates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: ExchRatesTable: Code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'training5_exchange_rates';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['label'] = '';
  $handler->display->display_options['fields']['code']['element_label_colon'] = FALSE;
  /* Field: ExchRatesTable: Rate */
  $handler->display->display_options['fields']['rate']['id'] = 'rate';
  $handler->display->display_options['fields']['rate']['table'] = 'training5_exchange_rates';
  $handler->display->display_options['fields']['rate']['field'] = 'rate';
  $handler->display->display_options['fields']['rate']['label'] = '';
  $handler->display->display_options['fields']['rate']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'exchange_rates/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Exchange Rates';
  $translatables['exchange_rates'] = array(
    t('Master'),
    t('Exchange Rates'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('.'),
    t(','),
    t('Page'),
  );
  $export[$view->name] = $view;
  return $export;
}
