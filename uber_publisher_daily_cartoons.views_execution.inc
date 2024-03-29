<?php

/**
 * @file
 * Contains uber_publisher_daily_cartoons.views_execution.inc file.
 */

/**
 * Implements hook_views_query_alter().
 */
function uber_publisher_daily_cartoons_views_query_alter($view, $query) {
  if ($view->id() == 'cartoons' && $view->current_display == 'cartoons_list') {
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as &$condition) {
        if (strpos($condition['field'], "DATE_FORMAT(node__field_date.field_date_value, '%Y-%m-%d') =") !== FALSE) {
          $condition['field'] = str_replace('=', '!=', $condition['field']);
        }
      }
    }
  }
}
