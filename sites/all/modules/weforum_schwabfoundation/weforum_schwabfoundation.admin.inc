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
    if ($queue) {
        $queue->deleteQueue();
        weforum_schwabfoundation_importf21();   
        $batch = batch_importf21();
        if (!empty($batch)) {
            batch_set($batch);
        } else {
            drupal_set_message('Problem with the export [batch], please contact the administrator');
        }
    } else {
            drupal_set_message('Problem with the export [queue], please contact the administrator');        
    }
}

function batch_importf21() {
    $num_operations = 100;  // callback every percent
    $queueName = 'socialentrepreneurs';
    $queue = DrupalQueue::get($queueName);

    $batch = NULL;

    if ($queue) {
        $node_count = $queue->numberOfItems();
        $nbItemsPerOp = ceil($node_count / $num_operations);
//        drupal_set_message(t('There are @node_count nodes so each of the @num operations will require @count HTTP requests.', array('@node_count' => $node_count, '@num' => $num_operations, '@count' => $nbItemsPerOp)));
        $operations = array();
        for ($i = 0; $i < $num_operations; $i++) {
            $operations[] = array('weforum_schwabfoundation_batch_processF21', array($nbItemsPerOp));
        }
        $batch = array(
            'operations' => $operations,
            'finished' => 'weforum_schwabfoundation_batch_finished',
            'title' => t('Import from Agora'),
            'init_message' => t('Agora import is starting.'),
    //        'progress_message' => t('Processed @current out of @total.'),
            'progress_message' => t(''),
            'error_message' => t('Agora Import has encountered an error.'),
        );
    }
    return $batch;
}

