<?php
/**
 * Form builder. Configurations
 */
function weforum_schwabfoundation_import_form() {
  $form['weforum_schwabfoundation_host'] = array(
    '#markup' => 'Clicking on Import will import the social entrepreneurs data from Agora<br>'
  );
  
  $form['weforum_schwabfoundation_import'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );
  
  return $form;
}

function weforum_schwabfoundation_import_form_submit($form, &$form_state)
{
    $queueName = 'socialentrepreneurs';
    $queue = DrupalQueue::get($queueName);
    $queue->deleteQueue();
    weforum_schwabfoundation_importf21();   
//    drupal_set_message('Test batch, found '.$queue->numberOfItems().' objects in queue');
//    $function = 'batch_example_' . $form_state['values']['batch'];

//    $_SESSION['http_request_count'] = 0; // reset counter for debug information.

    $batch = batch_importf21();
//    drupal_set_message('Starting batch');
    batch_set($batch);
}

function batch_importf21() {
    $num_operations = 100;
    // Give helpful information about how many nodes are being operated on.
    $queueName = 'socialentrepreneurs';
    $queue = DrupalQueue::get($queueName);


//    $node_count = db_query('SELECT COUNT(DISTINCT nid) FROM {node}')->fetchField();
//    $nbItemsPerOp = ceil($node_count / 5);
    $node_count = $queue->numberOfItems();
    $nbItemsPerOp = ceil($node_count / $num_operations);
//    drupal_set_message(t('There are @node_count nodes so each of the @num operations will require @count HTTP requests.', array('@node_count' => $node_count, '@num' => $num_operations, '@count' => $nbItemsPerOp)));
    $operations = array();
    // 20 operations, each one loads all nodes.
    for ($i = 0; $i < $num_operations; $i++) {
//    $operations[] = array('weforum_schwabfoundation_op_2', array(t('(Operation @operation)', array('@operation' => $i))));
        $operations[] = array('weforum_schwabfoundation_batch_processF21', array($nbItemsPerOp));
//        $operations[] = array('weforum_schwabfoundation_batch_processF21', array(t('(Operation @operation)', array('@operation' => $i))));
    }
    $batch = array(
        'operations' => $operations,
//        'finished' => 'weforum_schwabfoundation_finished',
        'finished' => 'weforum_schwabfoundation_batch_finished',
        // Message displayed while processing the batch. Available placeholders are:
        // @current, @remaining, @total, @percentage, @estimate and @elapsed.
        // These placeholders are replaced with actual values in _batch_process(),
        // using strtr() instead of t(). The values are determined based on the
        // number of operations in the 'operations' array (above), NOT by the number
        // of nodes that will be processed. In this example, there are 20
        // operations, so @total will always be 20, even though there are multiple
        // nodes per operation.
        // Defaults to t('Completed @current of @total.').
        'title' => t('Import from Agora'),
        'init_message' => t('Agora import is starting.'),
//        'progress_message' => t('Processed @current out of @total.'),
        'progress_message' => t(''),
        'error_message' => t('Agora Import has encountered an error.'),
    );
    return $batch;
}

