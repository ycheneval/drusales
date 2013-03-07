<?php

/**
 * Implements hook_drush_help()
 */
function weforum_schwabfoundation_drush_help($command) {
  switch ($command) {
    case 'drush:importf21':
      return dt('Import social entrepreneurs from F21');
      break;
  }
}

/**
 * Implements hook_drush_command()
 */
function weforum_schwabfoundation_drush_command() {
  $items = array();
  $items['importf21'] = array(
    'description' => dt('Import social entrepreneurs from F21'),
  );
  return $items;
}

function drush_weforum_schwabfoundation_importf21() {
 $count = weforum_schwabfoundation_importf21();
 drush_log($count . ' persons queued');
}

