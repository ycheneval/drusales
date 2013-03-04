<?php
/**
 * Form builder. Configurations
 */
function weforum_f21_admin_settings() {
  $form['weforum_f21_host'] = array(
    '#type' => 'textfield',
    '#title' => t('F21 Host'),
    '#default_value' => variable_get('weforum_f21_host', ''),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => TRUE,
    '#attributes' => array('autocomplete' => 'off'),
  );
  
  $form['weforum_f21_username'] = array(
    '#type' => 'textfield',
    '#title' => t('F21 User'),
    '#default_value' => variable_get('weforum_f21_username', ''),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => TRUE,
    '#attributes' => array('autocomplete' => 'off'),
  );
  $form['weforum_f21_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('weforum_f21_password', ''),
    '#size' => 20,
    '#maxlength' => 64,
    '#attributes' => array('autocomplete' => 'off'),
  );
  
  $form['weforum_f21_test'] = array(
    '#markup' => weforum_f21_test()?t('Connection successful'):t('Connection failed'),
  );
  
  return system_settings_form($form);
}