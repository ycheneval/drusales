<?php

/**
 * Returns the nid of an object having a salesforce id
 *
 * @param $id
 */
function weforum_salesforce_get_node($id){

}
/**
 * Check whether the $date is not older than shapers_salesforce_update_timeframe days
 *
 * @param $date
 * @return bool
 */
function weforum_salesforce_freshness_check($date) {
  $modified = new DateTime($date);
  $diff = date_diff($modified, new DateTime());
  $max_age = (int) variable_get('weforum_salesforce_update_timeframe', 7);
  return (!($diff->days > $max_age));
}

/**
 *  Updates a line (containing a record and a group)
 *
 * queue callback for a line
 * @param $item
 * @return bool
 */
function weforum_salesforce_update_line($hub) {
  //$hub = $item['Community__r'];


  // Get all entity ids of salesforce-nodes
  // SELECT entity_id from field_data_field_salesforce_id where field_salesforce_id_value in ($item 'id', $hub id)
  $query = db_select('field_data_field_salesforce_id', 'fsi');
  $query->addField('fsi', 'entity_id');
  $query->addField('fsi', 'field_salesforce_id_value');
  $results = $query
    ->execute()
    ->fetchAllKeyed();
  $mapping = array_flip($results);

  if(!weforum_salesforce_freshness_check($hub['Community__r']['LastModifiedDate']) AND (isset($mapping[$hub['Community__r']['Id']]))) {
    var_dump($hub['Community__r']['Name']);
    drush_log('not recently updated - do not process');
    return TRUE;
  }
  else {
    //Get the nid of the hub
    if (isset($mapping[$hub['Community__r']['Id']])) {
      $nid = $mapping[$hub['Community__r']['Id']];
    }
    else {
      $nid = FALSE;
    }
    weforum_salesforce_update_hub($hub, $nid);
    // Create the hub
    // Refresh hub
  }

  // check if modified recently or forced update
  if(!weforum_salesforce_freshness_check($hub['LastModifiedDate'])) {
    var_dump($hub['Name']);
    drush_log('too old - do not process');
    return TRUE;
  }
  else {
    //Refresh shaper

  }

  // Process the hub

  // Get the shaper

  // Is it old enough to process ?
  // Get the nid of the shaper
  // Get the picture of the shaper
  // Attribute special roles to the shaper

  return TRUE;

}
/**
 * Called by the weforum_salesforce_hubs queue worker callback: Updates a batch of Hubs.
 *
 * @param int $options
 *   An array of options to pass to the salesforce request.
 * @param int $limit
 *   The number of items to process at once.
 */
function weforum_salesforce_update_hubs($options, $limit) {
  $groups = salesforce_request_groups($options['page'], $options['per_page']);
  $salesforce_ids = array();
  foreach ($groups->group as $group) {
    $group_id = (int) $group->id;
    $salesforce_ids[$group_id] = $group;
  }
  foreach (_weforum_salesforce_process_results('field_salesforce_gid', 'hub', $salesforce_ids) as $result) {
    //if (!in_array((string)$result['salesforce_id']->{'do-not-sync'}, array('on', 'true'))) {
      $updated = weforum_salesforce_update_hub($result['salesforce_id'], $result['nid']);
      watchdog('weforum_salesforce', "%name hub updated", array('%name' => (string)$result['salesforce_id']->{'name'}, WATCHDOG_DEBUG));
      if ($updated) {
        //Update shapers
        $members = salesforce_request_members((string) $result['salesforce_id']->id);
        $salesforce_member_ids = array();
        //get a list of ids
        $query = db_select('field_data_group_audience', 'fdga');
        $query->join('og', 'og', 'fdga.group_audience_gid = og.gid');
        $query->join('field_data_field_tibbr_gid', 'fdtg', 'og.etid = fdtg.entity_id');
        $query->join('node', 'n', 'fdtg.entity_id = n.nid');
        $query->addField('fdga', 'entity_id');
        watchdog('weforum_salesforce', 'Populating %hub', array('%hub' => (string)$result['salesforce_id']->{'name'}), WATCHDOG_INFO);

        $results = $query
                ->condition('fdtg.field_salesforce_gid_value', (integer) $result['salesforce_id']->id)
                ->condition('fdga.bundle', 'shaper')
                ->condition('n.status', 1)
                ->execute()
                ->fetchAllAssoc('entity_id');

        foreach ($members->member as $member) {
          $member_id = (int) $member->id;
          $salesforce_member_ids[$member_id] = $member;
        }
        foreach (_weforum_salesforce_process_results('field_salesforce_id', 'shaper', $salesforce_member_ids) as $member_result) {
          if (!in_array((string)$member_result['salesforce_id']->{'do-not-sync'}, array('on', 'true'))) {
            weforum_salesforce_update_shaper($member_result['salesforce_id'], $member_result['nid']);
            unset($results[$member_result['nid']]);
          }
          else if (!empty($member_result['nid'])) {
            $node = node_load($member_result['nid']);
            node_unpublish_action($node);
            node_save($node);
            //remove id
            unset($results[$member_result['nid']]);
            watchdog('weforum_salesforce', 'Unpublishing %name ',array('%name' => $node->title), WATCHDOG_INFO);
          }
        }
        //unpublish the rest
        foreach ($results as $key => $data) {
          $node = node_load($key);
          watchdog('weforum_salesforce', 'Removing a shaper: %name not present in salesforce for %hub', array('%name' => $node->title, '%hub' => (string)$result['salesforce_id']->{'name'}), WATCHDOG_INFO);
          node_unpublish_action($node);
          node_save($node);
        }
      }
    /*
    }
    else if (!empty($result['nid'])) {
      $node = node_load($result['nid']);
      node_unpublish_action($node);
      node_save($node);
      watchdog('weforum_salesforce', 'Unpublishing %name', array('%name' => $node->title), WATCHDOG_INFO);
    }
    *
    */
  }
}

/**
 * Processes salesforce results.
 *
 * @param string $field
 *   The field representing this salesforce type.
 * @param string $type
 *   The type of salesforce data being imported.
 * @param array $salesforce_ids
 *   An array of SimpleXMLElement objects.
 *
 * @return array
 *   An associative array containing the following key-valu pairs:
 *   - nid: The ID of the node, or NULL.
 *   - salesforce_id: The SimpleXMLElement corresponding to the node.
 */
function _weforum_salesforce_process_results($field, $type, $salesforce_ids) {
  if (empty($salesforce_ids)) {
    return array();
  }

  $query = db_select('node', 'n');
  $query->join('field_data_' . $field, 't', 'n.nid = t.entity_id');
  $query->addField('n', 'nid');
  $salesforce_id_alias = $query->addField('t', $field . '_value');
  $results = $query
    ->condition('n.type', $type)
    ->condition($salesforce_id_alias, array_keys($salesforce_ids))
    ->execute()
    ->fetchAllKeyed();

  // Store the results for later reference.
  $salesforce_results = array_flip($results);
  // Collect all salesforce IDs that have an associated node.
  array_walk($results, function(&$value, $key) use ($salesforce_ids) {
    $value = array(
      'nid' => $key,
      'salesforce_id' => $salesforce_ids[$value],
    );
  });

  // Collect all salesforce IDs that do not have an associated node.
  foreach (array_diff_key($salesforce_ids, $salesforce_results) as $salesforce_id) {
    $results[] = array(
      'nid' => NULL,
      'salesforce_id' => $salesforce_id,
    );
  }
  return $results;
}

/**
 * Updates or creates a new shaper.
 *
 * @param SimpleXMLElement $account
 *   The XML representation of this shaper.
 * @param int|null $nid
 *   Either the shaper nid, or NULL.
 */
function weforum_salesforce_update_shaper(SimpleXMLElement $account, $nid = NULL) {
  $node = isset($nid) ? node_load($nid) : entity_create('node', array('type' => 'shaper'));
  if(!isset($nid)) {
    watchdog('weforum_salesforce', "Creating a new person", array(), WATCHDOG_INFO);
  }
  $wrapper = entity_metadata_wrapper('node', $node);

  // Populate a multiselect field with one or more values.
  // The keys correlate to a taxonomy term id, hence the missing value for 3.
  $expertise = array(
    0 => 'none',
    1 => 'arts',
    2 => 'business',
    4 => 'education',
    5 => 'entrepreneur',
    6 => 'fashion',
    7 => 'finance',
    8 => 'human',
    9 => 'law',
    10 =>'media',
    11 => 'politics',
    12 => 'science',
    13 => 'social',
    14 => 'sustainability',
    15 => 'health'
  );
  // Reset the field before we start to expunge old data.
  $wrapper->field_subject_tags = array();
  foreach ($expertise as $tid => $exp) {
    if (in_array((string) $account->{"exp-$exp"}, array('on', 'true'))) {
      // The elements in our $expertise array are in the same order as the tids
      // in the database. This could break if the terms in the database change
      // in the future.
      try {
        $wrapper->field_subject_tags[] = $tid;
      }
      catch (EntityMetadataWrapperException $e) {
      }
    }
  }

  // Assign the user a group audience based on the value of the hub property
  // coming form salesforce. $user_hub holds a string that should match the name of
  // a hub node, which is itself a group.
  $user_hub = (string) $account->department;
  // Look for hubs that match $user_hub.
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'hub')
    ->propertyCondition('title', $user_hub)
    ->execute();
  // If we found a hub then retrive the gid and if it's not the Global group,
  // make this shaper an audience of that group.
  if (!empty($entities['node'])) {
    $hub = reset($entities['node']);
    $group = og_get_group('node', $hub->nid);
    // @todo Figure out why this exists?
    if ($group->label != 'Global') {
      try {
        watchdog('weforum_salesforce', "%person attributed to %name", array('%name' => $group->label, "%person" => (string) $account->{'last-name'}), WATCHDOG_INFO);
        $wrapper->group_audience = array($group);
      }
      catch (EntityMetadataWrapperException $e) {
      }
      // Check to see if this shaper has the role of curator and assign the
      // node id to field_hub_curator, which is an entity reference field.

      if (((string) $account->{"role"} == 'Curator') AND $nid) {
        $hub_node = node_load($hub->nid);
        if ($hub_node->field_hub_curator['und'][0]['target_id'] != (int) $nid) {
          $hub_node->field_hub_curator['und'][0]['target_id'] = (int) $nid;
          watchdog('weforum_salesforce', "%person added as a curator to %name", array(
            '%name' => $group->label,
            "%person" => (string) $account->{'last-name'}
          ), WATCHDOG_INFO);
          node_save($hub_node);
        }
        else {
          watchdog('weforum_salesforce', "%person already curator to %name", array(
            '%name' => $group->label,
            "%person" => (string) $account->{'last-name'}
          ), WATCHDOG_INFO);
        }
      }
    }
  }

  // Because WEF's data is not sanitized and inconsistent, we need to filter out
  // any links that aren't properly structured URLs.
  $links = array(
    'facebook' => (string) $account->facebook,
    'linkedin' => (string) $account->{'linked-in'},
    'twitter' => (string) $account->twitter,
  );
  // Loop through the links and replace any that don't start with http:// with a blank string.
  foreach ($links as &$link) {
    $link = trim($link);
    // Ignore links not starting with http://.
    if (!valid_url($link, TRUE)) {
      $link = '';
    }
  }

  // Populate other fields with salesforce data.
  try {
    $wrapper->created = strtotime((string) $account->{'created-at'});
    $wrapper->field_salesforce_about_me->value = decode_entities((string) $account->description);
    $wrapper->field_salesforce_id = (int) $account->id;
    $wrapper->field_salesforce_first_name = decode_entities((string) $account->{'first-name'});
    $wrapper->field_salesforce_last_name = decode_entities((string) $account->{'last-name'});
    $wrapper->field_salesforce_nickname = decode_entities((string) $account->nickname);
    $wrapper->field_salesforce_organization = (string) $account->company;
    $wrapper->field_salesforce_email = (string) $account->email;
    if(valid_url($links['facebook'])){
      $wrapper->field_tibbr_facebook->url = $links['facebook'];
    }
    if(valid_url($links['twitter'])){
      $wrapper->field_tibbr_twitter->url = $links['twitter'];
    }
    if(valid_url($links['linkedin'])){
      $wrapper->field_salesforce_linkedin->url = $links['linkedin'];
    }
    $wrapper->field_tibbr_link->url = 'https://globalshapers.weforum.org' . '/tibbr/users/' . (int) $account->id . '/profile';
    $wrapper->field_tibbr_title = (string) $account->title;
    $wrapper->field_tibbr_username = (string) $account->login;
    $wrapper->field_joined = (string) strtotime($account->{'created-at'});
    $wrapper->field_salesforce_role = (string) $account->role;
  }
  catch (Exception $e) {
    drush_log($e->getMessage());
    watchdog('weforum_salesforce', $e->getMessage());
  }

  if ($media = (string) $account->{'media-profile'}) {
    try {
      $wrapper->field_video = (array) media_parse_to_file($media);
    }
    catch (Exception $e) {
      drush_log($e->getMessage());
      watchdog('weforum_salesforce', $e->getMessage());
    }
  }

  $fullname = $account->{'first-name'} . ' ' . $account->{'last-name'};
  $file = _weforum_salesforce_get_file((string) $account->{'profile-image-url'}, 'public://shaper-profile-images/' . strtolower(str_replace(' ', '-', $fullname)) . '-' . (string) $account->{'id'}, $fullname, FILE_EXISTS_REPLACE);
  try {
    if ($file) {
      $wrapper->field_shaper_profile_image = (array) $file;
    }
  }
  catch (EntityMetadataWrapperException $e) {
  }
  // Deleted shaper and still published ? Unpublish 
  if(((string)$account->deleted == 'true') && ($wrapper->status->value() == NODE_PUBLISHED)) {
    $wrapper->status->set(NODE_NOT_PUBLISHED);
    watchdog('weforum_salesforce', '%fullname unpublished', array('%fullname' => $fullname), WATCHDOG_INFO);
  }
  // Not deleted but unpublished ? Publish
  elseif (((string)$account->deleted == 'false') && ($wrapper->status->value() == NODE_NOT_PUBLISHED)) {
    $wrapper->status->set(NODE_PUBLISHED);
    watchdog('weforum_salesforce', '%fullname re-published', array('%fullname' => $fullname), WATCHDOG_INFO);
  } 
  
  try {
    $wrapper->save();
  }
  catch(Exception $e) {
    drush_log('weforum_salesforce save error -- ' . $e->getMessage());
    watchdog('weforum_salesforce', $e->getMessage());
  }
  return $node->nid;
}

/**
 * Update the Hub node passed into $node with the XML data passed by $group.
 */
function weforum_salesforce_update_hub($group, $nid) {
  $node = node_load($nid);
  $wrapper = entity_metadata_wrapper('node', $node);

  try {
    $wrapper->title->set($group['Community__r']['Name']);
    $wrapper->field_salesforce_id->set($group['Community__r']['Id']);
    $wrapper->body->value = html_entity_decode((string) $group['Community__r']['Description__c'], ENT_QUOTES, 'ISO-8859-1');
    $wrapper->created->set(time());
    $wrapper->field_tibbr_email = valid_email_address((string) $group['Community__r']['EmailAddress__c']) ? (string) $group['Community__r']['EmailAddress__c'] : '';
  }
    catch (EntityMetadataWrapperException $e) {
  }
  // Does the region exists ?
  $region = $group['Community__r']['Region__r']['Region_Code__c'];

  // Associate Hubs with region data.
  // The keys map to the names of elements returned from salesforce while the values
  // are the titles of Region nodes, which we need to use when we search for
  // those nodes using EntityFieldQuery.
  //var_dump($region);

  //Get all regions
  $query = new weforum_salesforce_query();
  $query->setQuery("SELECT+IsDeleted,+LastModifiedDate,+Id,+Region_Code__c,+Name+FROM+Region__c");
  $results = weforum_salesforce_query($query);
  //var_dump($results);
  // Magic functions with node,regions
  $results = weforum_salesforce_synchronize($results, 'node', 'region');

  foreach ($results['create'] as $key => $item) {
    $region = entity_create('node', array('type' => 'region'));
    $region_wrapper = entity_metadata_wrapper('node', $region);
    try {
      $region_wrapper->title->set($item['Name']);
      $region_wrapper->field_salesforce_id->set($item['Id']);
      $region_wrapper->created->set(strtotime($item['LastModifiedDate']));
    } catch (EntityMetadataWrapperException $e) {
        watchdog('weforum_salesforce', $e->getMessage(), array(), WATCHDOG_ALERT);
      return TRUE;
    }
    watchdog('weforum_salesforce', "Region %region created", array('%region' => $item['Name']), WATCHDOG_ALERT);
    $region_wrapper->save();
  }
  foreach($results['delete'] as $key => $item) {
    $node = node_load($item['nid']);
    node_unpublish_action($node);
    node_save($node);
  }

  // todo: update a region

  // Get the region
  // Get all entity bundles
  $query = db_select('field_data_field_salesforce_id', 'fds');
  $query->addField('fds', 'entity_id');
  $query->join('node', 'n', 'n.nid = fds.entity_id');
  $results = $query
    ->condition('fds.entity_type', 'node')
    ->condition('fds.bundle', 'region')
    ->condition('n.status', 1)
    ->condition('fds.field_salesforce_id_value', $group['Community__r']['Region__r']['Id'])
    ->execute()
    ->fetchAllAssoc('entity_id');
  $wrapper->field_region->set(array_keys($results));

  $wrapper->field_tibbr_facebook->set($group['Community__r']['FacebookURL__c']);
  $wrapper->field_tibbr_facebook_rss_link->set($group['Community__r']['FacebookFeedURL__c']);
  $wrapper->field_tibbr_twitter->set($group['Community__r']['TwitterURL__c']);


  try {
    $values = array();
    $values['lat'] = (float) $group['Community__r']['Latitude__c'];
    $values['lon'] = (float) $group['Community__r']['Longitude__c'];;
    $wrapper->field_lat_lon->set(geofield_compute_values($values, 'latlon'));
  } catch (EntityMetadataWrapperException $e){
    watchdog('weforum_salesforce', 'Error while setting lat long as %lat %long', $values , WATCHDOG_INFO);
  }
  //todo : get picture from salesforce
  //var_dump($group['Picture__c']);
  var_dump($group);
  $wrapper->save();
/*
  $file = _weforum_salesforce_get_file((string) $group->{'profile-image-url'}, 'public://hub-profile-images/' . strtolower($group->{'name'}), (string) $group->{'name'});
  try {
    if ($file) {
      $wrapper->field_salesforce_hub_profile_image = (array) $file;
    }
  }
  catch (EntityMetadataWrapperException $e) {
  }

  try {
    $wrapper->save();
  }
  catch (Exception $e) {
    watchdog('weforum_salesforce', $e->getMessage());
  }
*/

  /*


  // Loop through each member object to add this hub to a shaper's group
  // group audience.
  foreach ($group->members->member as $member) {
    // Find a shaper with the associated salesforce id.
    $query = new EntityFieldQuery();
    $shapers = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'shaper')
      ->fieldCondition('field_salesforce_id', 'value', (int) $member->id)
      ->execute();
    if (empty($shapers['node'])) {
      continue;
    }

    foreach ($shapers['node'] as $shaper) {
      // We have to load the shaper object so that we can add this group to
      // it and then use save it with node_save().
      $shaper = node_load($shaper->nid);
      // We need to get load the group object to get the gid so we can add it
      // to the shaper's group audience.
      // TODO: Getting lots of notices about the nid here.
      // Has this node necessarily been saved yet?
      $og_group = og_get_group('node', $node->nid);
      // Assure that this node is actually a group.
      if (!empty($og_group)) {
        $shaper_wrapper = entity_metadata_wrapper('node', $shaper);
        $shaper_wrapper->group_audience = array($og_group);
        try {
          $shaper_wrapper->save();
        }
        catch (PDOException $e) {
          watchdog('weforum_salesforce', $e->getMessage());
        }
      }

      // Check to see if this shaper has the role of curator and assign the
      // node id to field_hub_curator, which is an entity reference field.
      if ((string) $member->role == 'Curator') {
        try {
          $wrapper->field_hub_curator = $shaper->nid;
        }
        catch (EntityMetadataWrapperException $e) {
        }
      }
    }
  }


  $query = new EntityFieldQuery();
  $accounts = $query->entityCondition('entity_type', 'user')
    ->propertyCondition('name', (string) $group->name)
    ->execute();
  if (empty($accounts['user'])) {
    $account = array(
      'name' => (string) $group->name,
      'pass' => user_password(),
      'mail' => 'globalshapers@weforum.org',
      'init' => 'globalshapers@weforum.org',
      'status' => 1,
      'roles' => array(
        '5' => 'hub curator',
      ),
    );
    try {
      $account = user_save(NULL, $account);
    }
    catch (Exception $e) {
      drush_log('user save failed -- ' . $e->getMessage());
      watchdog('weforum_salesforce', $e->getMessage());
    }
  }
  else {
    $account = user_load(array_pop($accounts['user'])->uid);
  }
  // Assign the newly created user to a group and make admin.
  $g = og_get_group('node', $node->nid);
  og_group($g->gid, array(
    'entity type' => 'user',
    'entity' => $account,
    'membership type' => OG_MEMBERSHIP_TYPE_DEFAULT,
  ));
  og_role_grant($g->gid, $account->uid, 3);

  return $node->nid;
  */
}

/**
 * Creates a new local file for the remote URL passed in.
 *
 * @param string $url
 *   The remote URL of the file.
 * @param string $new_filepath
 *   The filepath to use for the local file.
 * @param string $alt
 *   The alt text to use for this file.
 ** @param $replace
 *   Replace behavior when the destination file already exists:
 *   - FILE_EXISTS_REPLACE - Replace the existing file. If a managed file with
 *       the destination name exists then its database entry will be updated. If
 *       no database entry is found then a new one will be created.
 *   - FILE_EXISTS_RENAME - Append _{incrementing number} until the filename is
 *       unique.
 *   - FILE_EXISTS_ERROR - Do nothing and return FALSE.
 *
 * @return object|null
 *   Either a file object, or NULL if one couldn't be created.
 */
function _weforum_salesforce_get_file($url, $new_filepath, $alt, $replace = FILE_EXISTS_RENAME) {
  $result = drupal_http_request($url, array('timeout' => 45));
  if ($result->code != 200) {
    watchdog('weforum_salesforce', 'HTTP error @errorcode occurred when trying to fetch @remote.', array('@errorcode' => $result->code, '@remote' => $url), WATCHDOG_ERROR);
    return;
  }
  // Create the file object.
  try {
    $file = file_save_data($result->data, $new_filepath, $replace);
    $file->alt = $alt;
    $file->title = $alt;
  }
  catch (PDOException $e) {
    watchdog('weforum_salesforce', $e->getMessage());
    return FALSE;
  }
  return $file;
}

