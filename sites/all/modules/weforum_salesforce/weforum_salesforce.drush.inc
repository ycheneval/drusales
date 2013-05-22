<?php

/**
 * @file
 *
 *   Provide drush access to salesforce migration and other salesforce functions as
 *   needed.
 *
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *   An associative array describing the drush commans.
 */
function weforum_salesforce_drush_command() {
  $items = array();

  $items['weforum-salesforce-import'] = array(
    'description' => 'Starts import of data from salesforce',
    'aliases' => array('wef-ti'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  $items['weforum-queue-delete'] = array(
    'description' => 'Deletes a queue',
    'aliases' => array('wef-qd'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  $items['gsf'] = array(
    'description' => 'Test function',
    'aliases' => array('gsf'),
  );
  return $items;
}



/**
 * Implements hook_drush_help().
 *
 * @param $section
 *   A string with the name of the help section (prepended with 'drush:')
 *
 * @return string
 *   A string with the help text for the command.
 */
function weforum_salesforce_drush_help($section) {
  switch ($section) {
    case 'drush:weforum-salesforce-import':
      return dt('Starts a batch process that imports data from salesforce');
    break;
    case 'drush:weforum-queue-delete':
      return dt('Deletes a queue');
    break;
  }
}

/**
 * Runs the import of data from salesforce.
 */
function drush_weforum_salesforce_import() {
  drush_print('Starting salesforce import.');
  $start = time();
  $result = weforum_salesforce_create_queue();
  $end = time();
  $diff = $end - $start;
  drush_print('salesforce import finished.');
  drush_print('Done in ' . $diff . ' seconds.');
}

/**
 * Deletes a queue
 *
 * @param $queue_name
 */
function drush_weforum_salesforce_weforum_queue_delete($queue_name) {
  DrupalQueue::get($queue_name)->deleteQueue();
  drush_print("Queue $queue_name deleted");
}


/**
 * Test function
 */
function drush_weforum_salesforce_gsf() {
  /*
  $results = weforum_salesforce_get_shapers(variable_get('weforum_salesforce_main_shapers_group', 0));
  var_dump(count($results['shapers']). ' shapers');
  var_dump(count($results['hubs']) . ' hubs');
  foreach ($results['shapers'] as $shaper) {
    weforum_salesforce_process_shaper($shaper, $force);
  }
  */
  weforum_salesforce_create_queue();

}