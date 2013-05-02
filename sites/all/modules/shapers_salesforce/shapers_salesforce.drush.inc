<?php
/**
 * Implements hook_drush_command().
 */
function shapers_salesforce_drush_command() {
  $items = array();
  $items['gsf'] = array(
    'description' => 'Test function',
    'aliases' => array('gsf'),
  );
  return $items;
}

/**
 * Test function
 */
function drush_shapers_salesforce_gsf() {
  shapers_salesforce_query('test');
}

