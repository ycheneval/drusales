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
  $items['soc-group'] = array(
    'description' => 'Test function',
    'aliases' => array('soct-group'),
  );
  $items['soc-feed'] = array(
    'description' => 'Test function',
    'aliases' => array('so-feeds'),
  );

  return $items;
}
function drush_salesforce_og_chatter_soc_group() {
    var_dump('Hello world');
    salesforce_og_chatter_get_groups();
////  foreach ($result as $key => $item) {
//    //var_dump($item['name']);
//    $members = salesforce_og_chatter_get_group_members($item);
//    var_dump($members);
//  }

  return 'yeah';
}

function drush_salesforce_og_chatter_soc_feed() {
//  $result = salesforce_og_chatter_paginated_call('chatter/feeds', 'feeds');
//  foreach ($result as $key => $item) {
//    var_dump($item);
//    $members = salesforce_og_chatter_get_group_members($item);
//    var_dump($members);
//  }

    
//    foreach ($result as $aFeed) {

//    $result = salesforce_og_chatter_paginated_call('chatter/feeds/user-profile/005b0000000Dy9dAAC/feed-items', 'items');    // Guillaume
//    $result = salesforce_og_chatter_paginated_call('chatter/feeds/user-profile/005b0000000ECT5AAO/feed-items', 'items');    // Me
//    foreach ($result as $aFeed) {
//    //var_dump($item['name']);
////    $members = salesforce_og_chatter_get_group_members($item);
//    var_dump($aFeed);
//  }

  return 'yeah';
}
