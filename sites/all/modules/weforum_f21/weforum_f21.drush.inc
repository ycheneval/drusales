<?php

/**
 * Implements hook_drush_help()
 */
function weforum_f21_drush_help($command) {
  switch ($command) {
    case 'drush:testf21':
      return dt('Test F21 connexion');
      break;
  }
}

/**
 * Implements hook_drush_command()
 */
function weforum_f21_drush_command() {
  $items = array();
  $items['testf21'] = array(
    'description' => dt('Test F21 connexion'),
  );
  return $items;
}

function drush_weforum_f21_testf21 () {
  if(!extension_loaded('mssql')){
    drush_log('marde');
  }
  drush_log('Running OK !');
}