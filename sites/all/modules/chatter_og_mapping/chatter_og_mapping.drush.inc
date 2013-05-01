<?php

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
  $communities = chatter_og_mapping_get_communities();
  $community = array_pop($communities);
  var_dump($community[0]);
  $community = (chatter_og_mapping_get_community($community[0]));
  drush_log("getting ". $community['id']);
  $records = chatter_og_mapping_get_record($community);
  $feeds = chatter_og_mapping_get_feed_items($community);
  var_dump($feeds);
  /*
  $groups = chatter_og_mapping_get_groups();
  $group = (array_pop($groups));
  $posts = chatter_og_mapping_get_posts($group);
  $post = array_pop($posts);
  $members = chatter_og_mapping_get_members($group);
  var_dump($members);
  */

  //$comments = chatter_og_mapping_get_comments($post);



return 'yeah';
}

