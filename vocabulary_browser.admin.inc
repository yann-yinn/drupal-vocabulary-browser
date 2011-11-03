<?php
/**
 * @file
 *
 * Admin form settings for vocabulary_browser
 */

function vocabulary_browser_settings_form() {
  $form = array();
  $form['#submit' ][] = 'vocabulary_browser_settings_form_submit';
  $form['vocabulary_browser_theme_path'] = array(
    '#title' => t('Choose vocabulary browser appearence'),
    '#type' => 'select',
    '#options' => vocabulary_browser_settings_form_themes_options(),
    '#default_value' => vocabulary_browser_theme_path_get(),
  );
  $form['vocabulary_browser_term_name_lenght'] = array(
    '#title' => t('Limit lenght of term names when displaying them under a folder'),
    '#type' => 'textfield',
    '#default_value' => variable_get('vocabulary_browser_term_name_lenght', 40),
    '#description' => t("set 0 for unlimited"),
  );
  $form['vocabulary_browser_display_parents_at_top'] = array(
    '#title' =>  t('Display terms without children at the bottom');
    '#type' => 'checkbox',
    '#default_value' => variable_get('vocabulary_browser_display_parents_at_top', 1),
  );
  return system_settings_form($form);
}

function vocabulary_browser_settings_form_themes_options() {
  $themes = module_invoke_all('vocabulary_browser_themes');
  $options = array();
  foreach ($themes as $name => $path) {
    $options[$path] = $name;
  }
  return $options;
}

/**
 * Submit callback for vocabulary_browser_settings_form
 */
function vocabulary_browser_settings_form_submit() {
  // @FIXME we need to rebuild theme only if theme choosen
  // is not the same as current theme
  cache_clear_all('theme_registry', 'cache', TRUE);
  drupal_set_message('Theme registry has been rebuild to active new theme for vocabulary_browser');
}
