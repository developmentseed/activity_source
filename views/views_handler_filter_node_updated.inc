<?php

/**
 * Detects whether a node has
 *
 */
class views_handler_filter_node_updated extends views_handler_filter_boolean_operator {
  /**
   * Add fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['created'] = 'created';
    $this->additional_fields['uid'] = 'uid';
  }

  /**
   * Override query().
   */
  function query() {
    $table_alias = $this->ensure_my_table();
    $this->query->add_field($table_alias, 'created');
    $this->query->add_field($table_alias, 'changed');

    // If a node has been changed within 60 seconds after creation it is deemed
    // updated.
    $op = empty($this->value) ? '<' : '>';
    $where = "$table_alias.changed $op ($table_alias.created + 60)";

    $this->query->add_where($this->options['group'], $where);
  }
}