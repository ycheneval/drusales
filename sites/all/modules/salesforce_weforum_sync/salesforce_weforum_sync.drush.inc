<?php

/**
 * @file
 * Drush integration for Salesforce.
 */

/**
 * Implements hook_drush_command().
 */
function salesforce_weforum_sync_drush_command() {
  $items = array();
  $items['soc-group'] = array(
    'description' => 'Test function',
    'aliases' => array('soct-group'),
  );


  return $items;
}
function drush_salesforce_weforum_sync_soc_group() {
    var_dump('Hello world');
    salesforce_weforum_sync_get_groups(true);

}
