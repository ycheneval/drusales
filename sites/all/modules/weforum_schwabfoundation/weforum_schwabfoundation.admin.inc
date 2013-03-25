<?php
/**
 * Form builder. Configurations
 */
function weforum_schwabfoundation_import_form() {
  $form['weforum_schwabfoundation_host'] = array(
    '#markup' => 'Clicking on the button will import the social entrepreneurs data from Agora<br>'
  );
  
  $form['weforum_schwabfoundation_import'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );
  
  return $form;
}

function weforum_schwabfoundation_import_form_submit($form, $form_state)
{
    $queue = DrupalQueue::get('socialentrepreneurs');
    $queue->deleteQueue();
    weforum_schwabfoundation_importf21();   
    weforum_schwabfoundation_import_form();
    drupal_set_message('Queue set');
}