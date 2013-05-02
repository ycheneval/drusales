<?php

/**
 * Implements hook_drush_command().
 */
function chatter_og_mapping_drush_command() {
  $items = array();
  $items['soc-test'] = array(
    'description' => 'Test function',
    'aliases' => array('soct-gb'),
  );
  return $items;
}

function drush_chatter_og_mapping_soc_test() {
  $groups = chatter_og_mapping_get_groups();
  $group = (array_pop($groups));
  $posts = chatter_og_mapping_get_posts($group);
  $post = array_pop($posts);
  $comments = chatter_og_mapping_get_comments($post);
  
  $result = chatter_og_mapping_post_group($group, 'yeah http://www.example.com');
  $results = chatter_og_mapping_get_group_members($group);
  while($post = array_pop($results)){
  var_dump($post);
    break;
  }
  

return 'yeah';
}

