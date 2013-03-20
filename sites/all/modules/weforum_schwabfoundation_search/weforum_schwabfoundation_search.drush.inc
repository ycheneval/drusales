<?php

/**
 * Implements hook_drush_help()
 */
function weforum_schwabfoundation_search_drush_help($command) {
  switch ($command) {
    case 'drush:listAOI':
      return dt('List the Area of Impacts on the site');
      break;
    case 'drush:listSectors':
      return dt('List the Sectors on the site');
      break;
    case 'drush:listModels':
      return dt('List the Models on the site');
      break;
  }
}

/**
 * Implements hook_drush_command()
 */
function weforum_schwabfoundation_search_drush_command() {
  $items = array();
  $items['listAOI'] = array(
    'description' => dt('List the Area of Impacts on the site'),
  );
  $items['listSectors'] = array(
    'description' => dt('List the Sectors on the site'),
  );
  $items['listModels'] = array(
    'description' => dt('List the Models on the site'),
  );
  return $items;
}

function drush_weforum_schwabfoundation_search_listAOI() {
 $records = weforum_schwabfoundation_search_listAOI();
 $i = 0;
 foreach ($records as $record) {
     drush_log('"'.$record->value.'" found'); 
     $i++;
 }
 drush_log($i . ' Area of Interest on the site');
}

function drush_weforum_schwabfoundation_search_listSectors() {
 $records =  weforum_schwabfoundation_search_listSectors();
 $i = 0;
 foreach ($records as $record) {
     drush_log('"'.$record->value.'" found'); 
     $i++;
 }
 drush_log($i . ' Sectors on the site');
}

function drush_weforum_schwabfoundation_search_listModels() {
 $records = weforum_schwabfoundation_search_listModels();
 $i = 0;
 foreach ($records as $record) {
     drush_log('"'.$record->value.'" found'); 
     $i++;
 }
 drush_log($i . ' Models on the site');
}

