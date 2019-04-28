<?php

/**
 * @file
 * Administration callbacks for the Dark Sky Forecast module.
 */

/**
 * Form builder. Configure Dark Sky.
 */
function ds_forecast_admin_settings() {

  $form['ds_forecast_api_key'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('API Key'),
    '#default_value' => variable_get('ds_forecast_api_key', ''),
    '#description' => t('Your API key from https://developer.forecast.io'),
    '#weight' => 0,
  );

  $form['ds_forecast_geo_lat'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Latitude'),
    '#default_value' => variable_get('ds_forecast_geo_lat', ''),
    '#description' => t('Latitude geo-coordinate. (example: 31.311556)'),
    '#weight' => 10,
  );

  $form['ds_forecast_geo_long'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Longitude'),
    '#default_value' => variable_get('ds_forecast_geo_long', ''),
    '#description' => t('Longitude geo-coordinate. (example: -92.445070'),
    '#weight' => 20,
  );

  $form['ds_forecast_period'] = array(
    '#type' => 'select',
    '#title' => t('Forecast Period'),
    '#default_value' => variable_get('ds_forecast_period', 'currently'),
    '#weight' => 30,
    '#options' => array(
      'currently' => t('Right Now'),
      'minutely' => t('Next 60 Minutes'),
      'hourly' => t('Next 24 Hours'),
      'daily' => t('Next 7 Days'),
    ),
  );

  $form['ds_forecast_cache_lifetime'] = array(
    '#type' => 'textfield',
    '#title' => t('Cache Lifetime (in seconds)'),
    '#description' => t('Leave blank or 0 to disable caching. Disable with caution. Minimum recommended value is 90.'),
    '#default_value' => variable_get('ds_forecast_cache_lifetime', '90'),
    '#weight' => 40,
    '#element_validate' => array('ds_forecast_validate_cache_lifetime'),
  );

  $form['#submit'][] = 'ds_forecast_admin_settings_submit';

  return system_settings_form($form);

}

/**
 * Validates the ds_forecast_cache_lifetime form element.
 *
 * @param mixed $element
 *   The form element being validated.
 * @param mixed $form_state
 *   The complete form containing the element being validated.
 */
function ds_forecast_validate_cache_lifetime($element, &$form_state) {
  if (!empty($element['#value']) && (!is_numeric($element['#value']) || intval($element['#value']) != $element['#value'] || $element['#value'] < 0)) {
    form_error($element, t('The "!name" option must be zero or a positive integer value.', array('!name' => check_plain($element['#title']))));
  }
}

/**
 * Process Dark Sky Forecast settings update.
 */
function ds_forecast_admin_settings_submit($form, $form_state) {

  // If the cache lifetime value is 0, we will not be caching at all. Clear
  // any cached data that may exist. No new data will be cached unless the
  // lifetime setting is changed to a positive integer.
  if ($form_state['values']['ds_forecast_cache_lifetime'] == 0) {
    cache_clear_all('ds_forecast:block', 'cache');
  }

}
