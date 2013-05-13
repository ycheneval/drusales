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
  $results = shapers_salesforce_get_shapers(variable_get('shapers_salesforce_main_shapers_group', 0));
  var_dump(count($results['shapers']). ' shapers');
  var_dump(count($results['hubs']) . ' hubs');
  foreach ($results['shapers'] as $key => $shaper) {
    shapers_salesforce_process_shaper($shaper);
  }

}

