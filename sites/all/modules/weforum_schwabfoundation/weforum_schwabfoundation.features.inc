<?php
/**
 * @file
 * weforum_schwabfoundation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function weforum_schwabfoundation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function weforum_schwabfoundation_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function weforum_schwabfoundation_node_info() {
  $items = array(
    'feed_post' => array(
      'name' => t('Feed post'),
      'base' => 'node_content',
      'description' => t('Content item fetched from Feeds module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('A news item'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Static pages like the "About us" page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'social_entrepreneur' => array(
      'name' => t('Social Entrepreneur'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'uploads' => array(
      'name' => t('Uploads'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
