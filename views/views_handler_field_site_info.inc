<?php
// $Id$

/**
 * A handler to provide a field that contains basic site information.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_site_info extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['site_info'] = array('default' => 'site_name');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array(
      'site_name' => t('Site name'),
      'base_url' => t('Base URL'),
    );
    $form['site_info'] = array(
      '#type' => 'select',
      '#title' => t('Site information'),
      '#description' => t('Site information to display.'),
      '#default_value' => $this->options['site_info'],
      '#options' => $options,
      '#weight' => -1,
    );
    $form['label']['#weight'] = -2;
  }

  function render($values) {
    switch ($this->options['site_info']) {
      case 'site_name':
        return variable_get('site_name', 'Drupal');
      case 'base_url':
        global $base_url;
        return $base_url;
    }
  }
}
