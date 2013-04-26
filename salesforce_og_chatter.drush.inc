<?php

/**
 * @file
 * Drush integration for Salesforce.
 */

/**
 * Implements hook_drush_command().
 */
function salesforce_og_chatter_drush_command() {
  $items = array();
  $items['soc-test'] = array(
    'description' => 'Test function',
    'aliases' => array('soct'),
  );

  return $items;
}
function drush_salesforce_og_chatter_soc_test() {
  $result = salesforce_og_chatter_paginated_call('chatter/groups', 'groups');
  foreach ($result as $$key => $item) {
    //var_dump($item['name']);
    $members = salesforce_og_chatter_get_group_members($item);
    var_dump($members);
  }

  return 'yeah';
}

