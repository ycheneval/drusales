<?php

/**
 * Implements hook_views_data_alter().
 */
function weforum_schwabfoundation_views_data_alter(&$data) {
  // Add filter on Feed importer ID that allows to list items link to
  // standalone (non node) feeds importers.
  $data['feeds_item']['id'] = array(
    'title' => t('Importer ID'),
    'help' => t('Contains the ID of the importer used to create the item.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
      'help' => t('Filter on a Feeds Item\'s importer id field.'),
    ),
    'sort' => array(
      'help' => t('Sort on a Feeds Item\'s importer id field.'),
    ),
  );
}
