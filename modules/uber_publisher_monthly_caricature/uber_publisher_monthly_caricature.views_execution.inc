<?php

/**
 * @file
 * Contains uber_publisher_monthly_caricature.views_execution.inc file.
 */

/**
 * Implements hook_views_query_alter().
 */
function uber_publisher_monthly_caricature_views_query_alter($view, $query) {
  if ($view->id() == 'monthly_cartoons' && $view->current_display == 'monthly_cartoons_list') {
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as &$condition) {
        if (strpos($condition['field'], "DATE_FORMAT(node__field_date.field_date_value, '%Y%m') =") !== FALSE) {
          $condition['field'] = str_replace('=', '!=', $condition['field']);
        }
      }
    }
  }
}
