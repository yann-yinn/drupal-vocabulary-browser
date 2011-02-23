<?php
function vocabulary_browser_settings_form() {
  $form = array();
  $form['#submit' ][] = 'vocabulary_browser_settings_form_submit';
  $form['vocabulary_browser_theme_path'] = array(
    '#title' => 'Choix du theme',
    '#type' => 'select',
    '#options' => vocabulary_browser_settings_form_themes_options(),
    '#default_value' => vocabulary_browser_theme_path_get(),
  );
  $form['vocabulary_browser_term_name_lenght'] = array(
    '#title' => 'Limiter la longueur des noms de termes affichés',
    '#type' => 'textfield',
    '#default_value' => variable_get('vocabulary_browser_term_name_lenght', 40),
    '#description' => "indiquez 0 pour illimité"
  );
  $form['vocabulary_browser_display_parents_at_top'] = array(
    '#title' => 'Afficher les termes parents en haut',
    '#type' => 'checkbox',
    '#default_value' => variable_get('vocabulary_browser_display_parents_at_top', 1),
    '#description' => "Note : l'ordre alphabétique restera respecté au sein des deux groupes de termes ainsi crées"
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
  cache_clear_all('theme_registry', 'cache', TRUE);
  drupal_set_message('Theme registry has been rebuild to active new theme for vocabulary_browser');
}
