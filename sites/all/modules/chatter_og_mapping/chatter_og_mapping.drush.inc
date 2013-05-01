<?php

/**
 * @file
 * Drush integration for Salesforce.
 */

/**
 * Implements hook_drush_command().
 */
function chatter_og_mapping_drush_command() {
  $items = array();
  $items['soc-test'] = array(
    'description' => 'Test function',
    'aliases' => array('soct'),
  );

  return $items;
}

function drush_chatter_og_mapping_soc_test() {

  $groups = chatter_og_mapping_get_groups();
  $group = (array_pop($groups));
  $posts = chatter_og_mapping_get_group_posts($group);
  $post = array_pop($posts);
  $comments = chatter_og_mapping_get_comments($post);



return 'yeah';
}

