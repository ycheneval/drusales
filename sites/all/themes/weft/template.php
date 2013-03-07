<?php

/**
 * @file
 * Theme functions for WEForum.
 */

/**
 * Implements hook_preprocess_HOOK() for page.tpl.php.
 */
function weft_preprocess_page(&$variables) {
  // Unset the breadcrumb.
  $variables['breadcrumb'] = '';

  $node = isset($variables['node']) ? $variables['node'] : NULL;
  $page_type = weforum_hub_get_page_type($node);
  if ($page_type == WEFORUM_HUB_GROUP_PAGE) {
    $group = og_context();
    $variables['title'] = l($group->label, $group->entity_type . '/' . $group->etid);
  }

  // Remove all but the first menu item on group pages.
  if ($page_type == WEFORUM_HUB_GROUP_PAGE || $page_type == WEFORUM_HUB_REGION_PAGE) {
    $key = key($variables['main_menu']);
    $variables['main_menu'] = array(
      $key => $variables['main_menu'][$key],
    );
  }
  if ($page_type == WEFORUM_HUB_REGION_PAGE) {
    $variables['title'] = l($node->title, 'node/' . $node->nid);
  }
  if ($page_type == WEFORUM_HUB_GLOBAL_PAGE && $node) {
    switch ($node->type) {
      case 'news':
        $variables['title'] = l('News & Events', 'news');
        break;
      case 'project':
        $variables['title'] = l('Projects', 'projects');
        break;
      case 'shaper':
        $variables['title'] = l('Shapers', 'shapers');
        break;
    }
  }
  $theme_path = drupal_get_path('theme', 'weft');

  // Add placeholder plugin
  drupal_add_js($theme_path . '/js/libs/jquery.html5-placeholder-shim.js');
  drupal_add_js($theme_path . '/js/ios-orientationchange-fix.js');

  drupal_add_js($theme_path . '/js/script.js');
  drupal_add_js($theme_path . '/js/ss-standard.js');
  drupal_add_js($theme_path . '/js/modernizr.custom.37877.js');
}

/**
 * Implements hook_preprocess_HOOK() for html.tpl.php.
 */
function weft_preprocess_html(&$variables) {
  global $language;
  if ($language->language == 'ar') {
    drupal_add_css(drupal_get_path('theme', 'weft') . '/css/font-face-arabic.css', array('group' => CSS_DEFAULT));
  }
  if (!weforum_hub_get_page_type()) {
    $variables['classes_array'][] = 'global-hub';
  }
}

/**
 * Implements theme_menu_local_task().
 */
function weft_menu_local_task__weforum_hub($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  $classes_array = array('weforum-local-task');
  if (isset($variables['element']['#weforum_hub_type'])) {
    $classes_array[] = $variables['element']['#weforum_hub_type'];
  }

  if (!empty($variables['element']['#active'])) {
    $classes_array[] = 'active';
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  $classes = implode(' ', $classes_array);
  return '<li class="' . $classes . '">' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * Implements hook_preprocess_HOOK() for theme_views_mini_pager().
 */
function weft_preprocess_views_mini_pager(&$variables) {
  // Override the strings used for mini pager links.
  $variables['tags'] = array(
    1 => t('Previous'),
    3 => t('Next'),
  );
}

/**
 * Implements hook_form_BASE_FORM_ID_alter() for webform_client_form().
 */
function weft_form_webform_client_form_alter(&$form, &$form_state, $form_id) {
  if (!isset($form['submitted'])) {
    return;
  }

  foreach ($form['submitted'] as $key => $value) {
    if (in_array($value["#type"], array('textfield', 'webform_email', 'textarea'))) {
      $form['submitted'][$key]['#attributes']['placeholder'] = $value['#title'];
    }
  }
}

/**
 * Returns HTML for the inactive facet item's count.
 *
 * @param $variables
 *   An associative array containing:
 *   - count: The item's facet count.
 *
 * @ingroup themeable
 */
function weft_facetapi_count($variables) {
  global $language;
  $dir = ($language->direction == 1) ? 'rtl' : 'ltr';
  return '<span dir="'.$dir.'">(' . (int) $variables['count'] . ')</span>';
}
