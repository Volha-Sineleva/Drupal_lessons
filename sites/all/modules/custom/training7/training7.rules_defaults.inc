<?php

/**
 * Implements hook_default_rules_configuration().
 */
function training7_default_rules_configuration() {
  $items = array(
    'training7_rule' => entity_import('rules_config',
      '{ "rules_run_a_lottery" : {
          "LABEL" : "Run a lottery",
          "PLUGIN" : "reaction rule",
          "OWNER" : "rules",
          "REQUIRES" : [ "training7" ],
          "ON" : { "training7_user_visited_lottery" : [] },
          "IF" : [ { "training7_lottery_result" : [] } ],
          "DO" : [ { "training7_show_lottery_win_message" : [] } ]
        }
      }'),
  );
  return $items;
}