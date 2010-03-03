<?php

/**
 * Implementation of hook_views_default_views().
 */
function activity_source_views_default_views() {
  module_load_include('inc', 'activity_source', 'activity_source.features.views');
  $args = func_get_args();
  return call_user_func_array('_activity_source_views_default_views', $args);
}
