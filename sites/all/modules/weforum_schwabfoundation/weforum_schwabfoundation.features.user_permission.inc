<?php
/**
 * @file
 * weforum_schwabfoundation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function weforum_schwabfoundation_user_default_permissions() {
  $permissions = array();

  // Exported permission: Agora import.
  $permissions['Agora import'] = array(
    'name' => 'Agora import',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'weforum_schwabfoundation',
  );

  // Exported permission: Blog import.
  $permissions['Blog import'] = array(
    'name' => 'Blog import',
    'roles' => array(),
    'module' => 'weforum_schwabfoundation',
  );

  // Exported permission: Facebook import.
  $permissions['Facebook import'] = array(
    'name' => 'Facebook import',
    'roles' => array(),
    'module' => 'weforum_schwabfoundation',
  );

  // Exported permission: Twitter import.
  $permissions['Twitter import'] = array(
    'name' => 'Twitter import',
    'roles' => array(),
    'module' => 'weforum_schwabfoundation',
  );

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(),
    'module' => 'contextual',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access statistics.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(),
    'module' => 'statistics',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer custom content.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: administer facets.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: administer feeds.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: administer media.
  $permissions['administer media'] = array(
    'name' => 'administer media',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'media',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer redirects.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(),
    'module' => 'redirect',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(),
    'module' => 'search_api',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer statistics.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(),
    'module' => 'statistics',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: clear facebook feeds.
  $permissions['clear facebook feeds'] = array(
    'name' => 'clear facebook feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: create blog_entry content.
  $permissions['create blog_entry content'] = array(
    'name' => 'create blog_entry content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create feed_post content.
  $permissions['create feed_post content'] = array(
    'name' => 'create feed_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create news content.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: create social_entrepreneur content.
  $permissions['create social_entrepreneur content'] = array(
    'name' => 'create social_entrepreneur content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create twitter_oauth content.
  $permissions['create twitter_oauth content'] = array(
    'name' => 'create twitter_oauth content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create uploads content.
  $permissions['create uploads content'] = array(
    'name' => 'create uploads content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: delete any blog_entry content.
  $permissions['delete any blog_entry content'] = array(
    'name' => 'delete any blog_entry content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any feed_post content.
  $permissions['delete any feed_post content'] = array(
    'name' => 'delete any feed_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any news content.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any social_entrepreneur content.
  $permissions['delete any social_entrepreneur content'] = array(
    'name' => 'delete any social_entrepreneur content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any twitter_oauth content.
  $permissions['delete any twitter_oauth content'] = array(
    'name' => 'delete any twitter_oauth content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any uploads content.
  $permissions['delete any uploads content'] = array(
    'name' => 'delete any uploads content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own blog_entry content.
  $permissions['delete own blog_entry content'] = array(
    'name' => 'delete own blog_entry content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own feed_post content.
  $permissions['delete own feed_post content'] = array(
    'name' => 'delete own feed_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own news content.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own social_entrepreneur content.
  $permissions['delete own social_entrepreneur content'] = array(
    'name' => 'delete own social_entrepreneur content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own twitter_oauth content.
  $permissions['delete own twitter_oauth content'] = array(
    'name' => 'delete own twitter_oauth content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own uploads content.
  $permissions['delete own uploads content'] = array(
    'name' => 'delete own uploads content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: edit any blog_entry content.
  $permissions['edit any blog_entry content'] = array(
    'name' => 'edit any blog_entry content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any feed_post content.
  $permissions['edit any feed_post content'] = array(
    'name' => 'edit any feed_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any news content.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any social_entrepreneur content.
  $permissions['edit any social_entrepreneur content'] = array(
    'name' => 'edit any social_entrepreneur content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any twitter_oauth content.
  $permissions['edit any twitter_oauth content'] = array(
    'name' => 'edit any twitter_oauth content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any uploads content.
  $permissions['edit any uploads content'] = array(
    'name' => 'edit any uploads content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit media.
  $permissions['edit media'] = array(
    'name' => 'edit media',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'media',
  );

  // Exported permission: edit own blog_entry content.
  $permissions['edit own blog_entry content'] = array(
    'name' => 'edit own blog_entry content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own feed_post content.
  $permissions['edit own feed_post content'] = array(
    'name' => 'edit own feed_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own news content.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own social_entrepreneur content.
  $permissions['edit own social_entrepreneur content'] = array(
    'name' => 'edit own social_entrepreneur content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own twitter_oauth content.
  $permissions['edit own twitter_oauth content'] = array(
    'name' => 'edit own twitter_oauth content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own uploads content.
  $permissions['edit own uploads content'] = array(
    'name' => 'edit own uploads content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: import facebook feeds.
  $permissions['import facebook feeds'] = array(
    'name' => 'import facebook feeds',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import media.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'media',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: unlock facebook feeds.
  $permissions['unlock facebook feeds'] = array(
    'name' => 'unlock facebook feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format simple_html.
  $permissions['use text format simple_html'] = array(
    'name' => 'use text format simple_html',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'filter',
  );

  // Exported permission: view advanced help index.
  $permissions['view advanced help index'] = array(
    'name' => 'view advanced help index',
    'roles' => array(),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help popup.
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help topic.
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(),
    'module' => 'advanced_help',
  );

  // Exported permission: view media.
  $permissions['view media'] = array(
    'name' => 'view media',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'publisher' => 'publisher',
    ),
    'module' => 'media',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: view post access counter.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(),
    'module' => 'statistics',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
