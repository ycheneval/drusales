<?php

/**
 * @file
 *  This template handles the featured sliders view and prevents multiple images
 *  from showing up when Shapers are added to sliders.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
  // If a slide is a shaper, don't output media field.
  if (isset($row->node_type) && $row->node_type == 'shaper') {
    $output = $field->last_render = '';
  }
  print $output;
?>
