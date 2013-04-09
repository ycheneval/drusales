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
 * Implements hook_image_default_styles().
 */
function weforum_schwabfoundation_image_default_styles() {
  $styles = array();

  // Exported image style: img150-90.
  $styles['img150-90'] = array(
    'name' => 'img150-90',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '150',
          'height' => '90',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: img700-400.
  $styles['img700-400'] = array(
    'name' => 'img700-400',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '700',
          'height' => '400',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
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
    'twitter_oauth' => array(
      'name' => t('Twitter oAuth'),
      'base' => 'node_content',
      'description' => t('Used now to connect to Twitter to fetch tweets'),
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
