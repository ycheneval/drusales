<?php
/**
 * @file
 * weforum_schwabfoundation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function weforum_schwabfoundation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'carousel_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured';
  $handler->display->display_options['css_class'] = 'weforum-slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'weforum-slideshow-item';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = 'Nodequeue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'homepage' => 'homepage',
  );
  /* Field: Content: per_image */
  $handler->display->display_options['fields']['field_per_image']['id'] = 'field_per_image';
  $handler->display->display_options['fields']['field_per_image']['table'] = 'field_data_field_per_image';
  $handler->display->display_options['fields']['field_per_image']['field'] = 'field_per_image';
  $handler->display->display_options['fields']['field_per_image']['label'] = '';
  $handler->display->display_options['fields']['field_per_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_per_image']['empty'] = '<img src="/sites/default/files/logo_large_whiter.png" width="800">';
  $handler->display->display_options['fields']['field_per_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_per_image']['settings'] = array(
    'image_style' => 'img700-400',
    'image_link' => '',
  );
  /* Field: Opening tags */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Opening tags';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '            <div class="slider-wrapper News">
                <div class="bottom-wrapper">
';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_class'] = 'date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j M Y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Closing tags */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Closing tags';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '                </div>
            </div>    
';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['carousel_'] = $view;

  $view = new view();
  $view->name = 'feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'url' => 'url',
    'created' => 'created',
  );
  $handler->display->display_options['row_options']['separator'] = '•';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Twitter</h2>
<a href="https://twitter.com/schwabfound">Follow us ></a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '1000';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'twitter_oauth' => 'twitter_oauth',
  );

  /* Display: Global Twitter */
  $handler = $view->new_display('panel_pane', 'Global Twitter', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'twitter-stream-display';

  /* Display: Global Facebook */
  $handler = $view->new_display('panel_pane', 'Global Facebook', 'panel_pane_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'facebook-stream-display';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Facebook</h2>
<a href="https://www.facebook.com/schwabfound">Follow us ></a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'feed_post' => 'feed_post',
  );
  /* Filter criterion: Feeds item: Importer ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'feeds_item';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['value'] = 'facebook';
  $export['feeds'] = $view;

  $view = new view();
  $view->name = 'news_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '        <div class="node node-news view-mode-search_result clearfix weforum-layout-list">
            <div class="weforum-listing left">
';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: per_image */
  $handler->display->display_options['fields']['field_per_image']['id'] = 'field_per_image';
  $handler->display->display_options['fields']['field_per_image']['table'] = 'field_data_field_per_image';
  $handler->display->display_options['fields']['field_per_image']['field'] = 'field_per_image';
  $handler->display->display_options['fields']['field_per_image']['label'] = '';
  $handler->display->display_options['fields']['field_per_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_per_image']['empty'] = '<img src="/sites/all/themes/weft/logo.png" width="100" height="100">';
  $handler->display->display_options['fields']['field_per_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_per_image']['settings'] = array(
    'image_style' => 'img150-90',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '            </div>
            <div class="weforum-listing middle">
                <div class="top">
';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '                </div>
                <div class="bottom">
';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '                </div>
            </div>
            <div class="weforum-listing right">
';
  $handler->display->display_options['fields']['nothing_3']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_3']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_3']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_3']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '            </div>
        </div>';
  $handler->display->display_options['fields']['nothing_4']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_4']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_4']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_4']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
    'social_entrepreneur' => 'social_entrepreneur',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['news_items'] = $view;

  $view = new view();
  $view->name = 'test';
  $view->description = 'Entrepreneurs table with search';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Entrepreneurs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Entrepreneurs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_org_public_name' => 'field_org_public_name',
    'field_area_of_impact' => 'field_area_of_impact',
    'field_sector' => 'field_sector',
    'field_model' => 'field_model',
  );
  $handler->display->display_options['style_options']['default'] = 'field_org_public_name';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_public_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_area_of_impact' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sector' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_model' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: full_name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_full_name]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_org_public_name']['id'] = 'field_org_public_name';
  $handler->display->display_options['fields']['field_org_public_name']['table'] = 'field_data_field_org_public_name';
  $handler->display->display_options['fields']['field_org_public_name']['field'] = 'field_org_public_name';
  /* Field: Content: Area of impact */
  $handler->display->display_options['fields']['field_area_of_impact']['id'] = 'field_area_of_impact';
  $handler->display->display_options['fields']['field_area_of_impact']['table'] = 'field_data_field_area_of_impact';
  $handler->display->display_options['fields']['field_area_of_impact']['field'] = 'field_area_of_impact';
  $handler->display->display_options['fields']['field_area_of_impact']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_area_of_impact']['separator'] = ' ';
  /* Field: Content: Sector */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['delta_offset'] = '0';
  /* Field: Content: Model */
  $handler->display->display_options['fields']['field_model']['id'] = 'field_model';
  $handler->display->display_options['fields']['field_model']['table'] = 'field_data_field_model';
  $handler->display->display_options['fields']['field_model']['field'] = 'field_model';
  $handler->display->display_options['fields']['field_model']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'social_entrepreneur' => 'social_entrepreneur',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: full_name (field_full_name) */
  $handler->display->display_options['filters']['field_full_name_value']['id'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['filters']['field_full_name_value']['field'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_full_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_full_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_full_name_value']['expose']['operator_id'] = 'field_full_name_value_op';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['operator'] = 'field_full_name_value_op';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['identifier'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Organization (field_org_public_name) */
  $handler->display->display_options['filters']['field_org_public_name_value']['id'] = 'field_org_public_name_value';
  $handler->display->display_options['filters']['field_org_public_name_value']['table'] = 'field_data_field_org_public_name';
  $handler->display->display_options['filters']['field_org_public_name_value']['field'] = 'field_org_public_name_value';
  $handler->display->display_options['filters']['field_org_public_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_org_public_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_org_public_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_org_public_name_value']['expose']['operator_id'] = 'field_org_public_name_value_op';
  $handler->display->display_options['filters']['field_org_public_name_value']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_org_public_name_value']['expose']['operator'] = 'field_org_public_name_value_op';
  $handler->display->display_options['filters']['field_org_public_name_value']['expose']['identifier'] = 'field_org_public_name_value';
  $handler->display->display_options['filters']['field_org_public_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Area of impact (field_area_of_impact) */
  $handler->display->display_options['filters']['field_area_of_impact_value']['id'] = 'field_area_of_impact_value';
  $handler->display->display_options['filters']['field_area_of_impact_value']['table'] = 'field_data_field_area_of_impact';
  $handler->display->display_options['filters']['field_area_of_impact_value']['field'] = 'field_area_of_impact_value';
  $handler->display->display_options['filters']['field_area_of_impact_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_area_of_impact_value']['group'] = 1;
  $handler->display->display_options['filters']['field_area_of_impact_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_area_of_impact_value']['expose']['operator_id'] = 'field_area_of_impact_value_op';
  $handler->display->display_options['filters']['field_area_of_impact_value']['expose']['label'] = 'Area of impact';
  $handler->display->display_options['filters']['field_area_of_impact_value']['expose']['operator'] = 'field_area_of_impact_value_op';
  $handler->display->display_options['filters']['field_area_of_impact_value']['expose']['identifier'] = 'field_area_of_impact_value';
  $handler->display->display_options['filters']['field_area_of_impact_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Sector (field_sector) */
  $handler->display->display_options['filters']['field_sector_value']['id'] = 'field_sector_value';
  $handler->display->display_options['filters']['field_sector_value']['table'] = 'field_data_field_sector';
  $handler->display->display_options['filters']['field_sector_value']['field'] = 'field_sector_value';
  $handler->display->display_options['filters']['field_sector_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_sector_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sector_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sector_value']['expose']['operator_id'] = 'field_sector_value_op';
  $handler->display->display_options['filters']['field_sector_value']['expose']['label'] = 'Sector';
  $handler->display->display_options['filters']['field_sector_value']['expose']['operator'] = 'field_sector_value_op';
  $handler->display->display_options['filters']['field_sector_value']['expose']['identifier'] = 'field_sector_value';
  $handler->display->display_options['filters']['field_sector_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Model (field_model) */
  $handler->display->display_options['filters']['field_model_value']['id'] = 'field_model_value';
  $handler->display->display_options['filters']['field_model_value']['table'] = 'field_data_field_model';
  $handler->display->display_options['filters']['field_model_value']['field'] = 'field_model_value';
  $handler->display->display_options['filters']['field_model_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_model_value']['group'] = 1;
  $handler->display->display_options['filters']['field_model_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_value']['expose']['operator_id'] = 'field_model_value_op';
  $handler->display->display_options['filters']['field_model_value']['expose']['label'] = 'Model';
  $handler->display->display_options['filters']['field_model_value']['expose']['operator'] = 'field_model_value_op';
  $handler->display->display_options['filters']['field_model_value']['expose']['identifier'] = 'field_model_value';
  $handler->display->display_options['filters']['field_model_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'entrepreneurs';
  $export['test'] = $view;

  return $export;
}
