<?php

/**
 * Implementation of hook_views_data().
 */
function activity_source_views_data() {
}

/**
 * Implementation of hook_views_data_alter().
 */
function activity_source_views_data_alter(&$data) {
  // Expose site information, views patch submitted at
  // http://drupal.org/node/730752
  $data['views']['site_info'] = array(
    'title' => t('Site information'),
    'help' => t('Basic information about this site like its name or the base URL.'),    
    'field' => array(
      'handler' => 'views_handler_field_site_info',
    ),
  );

  // Expose authmap table, views patch submitted at
  // http://drupal.org/node/730810
  $data['authmap']['table']['group']  = t('User');
  $data['authmap']['table']['join'] = array(
    // Directly links to users table.
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'node' => array(
      'left_table' => 'users',
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  $data['authmap']['aid'] = array(
    'title' => t('Authmap ID'),
    'help' => t('The Authmap ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'numeric' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
  );
  $data['authmap']['authname'] = array(
    'title' => t('Authentication name'),
    'help' => t('The unique authentication name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['authmap']['module'] = array(
    'title' => t('Authentication module'),
    'help' => t('The name of the module managing the authentication entry.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'numeric' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
}

/**
 * Implementation of hook_views_handlers()
 */
function activity_source_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'activity_source') . '/views',
    ),
    'handlers' => array(
      'views_handler_field_site_info' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
