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
    isDeniedSync(true);
    $sfIds_salesforce_groups = salesforce_weforum_sync_get_groups(true);
    $sfIds_salesforce_projects = salesforce_weforum_sync_get_projects(true);
    // Testing the full sync

    $sfIds_salesforce = array_merge(myarray_recursive_flatten($sfIds_salesforce_groups), myarray_recursive_flatten($sfIds_salesforce_projects));
    fullSync($sfIds_salesforce);
//    var_dump(salesforce_weforum_sync_get_dplGroupStructure());
    isDeniedSync(false);

}
