<?php

/**
 * Ctools content type (panel pane) for the change hub/region section.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Hub Search'),
  'description' => t('Hub search pane'),
  'defaults' => '',
  'category' => t('WEForum'),
  'render callback' => 'weforum_hub_search_content_type_render',
);


function weforum_hub_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = NULL;
  $page_type = weforum_hub_get_page_type($node);
  $currently_string = '<span class="title-choose-hub">' . t('Choose Hub/Region') . '</span> <span class="title-label">' . t('You are currently:') . '</span> ';
  $block->title = $page_type == WEFORUM_HUB_REGION_PAGE ? $node->title : weforum_hub_get_hub_title();
  $block->title = !empty($block->title) ? $currently_string . $block->title : '';
  $elements[] = array(
    '#theme' => 'image_formatter',
    '#prefix' => '<a href="/hubs">',
    '#suffix' => '</a>',
    '#item' => array(
      'uri' => drupal_get_path('theme', 'weft') . '/images/weforum_map.png',
      'alt' => t('Map of hubs'),
      'title' => t('Hub Map'),
    ),
    '#access' => arg(0) != 'hubs',
  );
  $result = db_query("SELECT title, nid FROM {node} WHERE type = 'hub' OR type = 'region' AND status = 1");
  foreach ($result as $hub) {
    $hubs[] = array(
      'url' => url("node/$hub->nid"),
      'label' => check_plain($hub->title),
      'value' => check_plain($hub->title),
    );
  }
  $elements['#attached'] = array(
    'library' => array(
      array('system', 'ui.autocomplete'),
    ),
    'js' => array(
      ctools_attach_js('weforum_hub', 'weforum_hub'),
      array('data' => array('weforumHubs' => $hubs), 'type' => 'setting'),
    ),
  );
  $elements[] = weforum_hub_get_map_search();

  $facts = array(
    weforum_hub_get_global_hub_count(),
    weforum_hub_get_global_shaper_count(),
  );
  if ($page_type == WEFORUM_HUB_REGION_PAGE) {
    $facts[] = weforum_hub_get_region_shaper_count($node->nid, $node->title);
  }
  elseif ($page_type == WEFORUM_HUB_GROUP_PAGE) {
    $facts[] = weforum_hub_get_hub_shaper_count();
  }
  foreach ($facts as $fact) {
    $elements[] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'weforum-facts',
        ),
      ),
      'fact' => array(
        '#markup' => $fact,
      ),
    );
  }

  $block->content = $elements;
  return $block;
}

function weforum_hub_get_hub_title() {
  $group = og_context();
  if (!$group) {
    if (arg(0) == 'hubs') {
      return '';
    }
    return t('Global');
  }
  else {
    $hub = node_load($group->etid);
    return check_plain($hub->title);
  }
}

function weforum_hub_get_map_search() {
  $view = views_get_view('hubs');
  if ($view && $view->access('panel_pane_1')) {
    $view->set_display('panel_pane_1');
    $view->init_handlers();
    $exposed_form = $view->display_handler->get_plugin('exposed_form');
    $exposed_form->view->override_path = 'hubs';
    $exposed_form = $exposed_form->render_exposed_form(TRUE);
    return array(
      '#markup' => $exposed_form,
    );
  }
  return array();
}

function weforum_hub_get_global_hub_count() {
  $number = db_query("SELECT count(nid) FROM {node} WHERE type = 'hub' AND status = 1")->fetchField();
  return t('Number of Hubs Globally: %number', array('%number' => $number));
}

function weforum_hub_get_global_shaper_count() {
  $number = db_query("SELECT count(nid) FROM {node} WHERE type = 'shaper' AND status = 1")->fetchField();
  return t('Number of Shapers: %number', array('%number' => $number));
}

function weforum_hub_get_hub_shaper_count() {
  $group = og_context();
  $number = db_query("SELECT count(nid) FROM {node} n INNER JOIN {og_membership} o ON o.etid = n.nid WHERE o.entity_type = 'node' AND o.gid = :gid AND n.type = 'shaper' AND n.status = 1", array(':gid' => $group->gid))->fetchField();
  $hub = node_load($group->etid);
  return t('Number of @hub Shapers: %number', array('@hub' => $hub->title, '%number' => $number));
}

function weforum_hub_get_region_shaper_count($nid, $title) {
  $results = db_query("SELECT o.gid FROM og o INNER JOIN  field_data_field_region r ON o.etid = r.entity_id WHERE r.field_region_target_id = :nid", array(':nid' => $nid))->fetchAll();

  if (empty($results)) {
    return t('Number of @region Shapers: 0', array('@region' => $title));
  }

  else {
    $gids = array();
    foreach ($results as $key => $result) {
      $gids[] = $result->gid;
    }
    $number = db_query("SELECT count(nid) FROM {node} n INNER JOIN {og_membership} o ON o.etid = n.nid WHERE o.entity_type = 'node' AND o.gid IN (:gids) AND n.type = 'shaper' AND n.status = 1", array(':gids' => $gids))->fetchField();

    return t('Number of @region Shapers: %number', array('@region' => $title, '%number' => $number));
  }
}
