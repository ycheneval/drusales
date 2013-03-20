<?php

/**
 * @file
 * Plugin to provide access control based on page type.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("WEForum Page Type"),
  'description' => t('Choose the page type to match.'),
  'callback' => 'weforum_hub_page_type_access_check',
  'default' => array('page_type' => ''),
  'settings form' => 'weforum_hub_page_type_access_settings',
  'summary' => 'weforum_hub_page_type_access_summary',
  'all contexts' => TRUE,
);

function weforum_hub_page_type_access_settings($form, &$form_state, $conf) {
  $form['settings']['page_type'] = array(
    '#type' => 'radios',
    '#title' => t('Page type'),
    '#default_value' => $conf['page_type'],
    '#description' =>  t('@todo.'),
    '#options' => array(
      WEFORUM_HUB_GLOBAL_PAGE => t('Global page'),
      WEFORUM_HUB_GROUP_PAGE => t('Group page'),
      WEFORUM_HUB_REGION_PAGE => t('Region page'),
    ),
  );
  return $form;
}

function weforum_hub_page_type_access_check($conf, $contexts) {
  return weforum_hub_get_page_type() == $conf['page_type'];
}

function weforum_hub_page_type_access_summary($conf, $contexts) {
  $map = array(
    WEFORUM_HUB_GLOBAL_PAGE => t('Global page'),
    WEFORUM_HUB_GROUP_PAGE => t('Group page'),
    WEFORUM_HUB_REGION_PAGE => t('Region page'),
  );
  return $map[$conf['page_type']];
}
