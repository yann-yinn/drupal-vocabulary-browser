Il est possible de créer de nouveaux themes pour la présentation
des termes dans vocabulary browser. Il sera ensuite possible de changer
le theme via l'administration dans admin/settings/vocabulary-browser

Il faut d'abord copier coller des themes, par exemple "explorer" 
dans le dossier de votre choix

Ensuite il faut déclarer l'existence de ce theme à vocabulary browser
en lui indiquant son nom et son chemin dans le hook_vocabulary_browser_themes()
C'est ainsi que le module vocabulary_browser déclarer ses propres thèmes :

/**
 * Implements hook_vocabulary_browser_themes();
 */
function vocabulary_browser_vocabulary_browser_themes() {
  $path = drupal_get_path('module', 'vocabulary_browser') . '/themes';
  return array(
    'Explorer' => $path . '/explorer',
    'Simple'   => $path . '/simple',
  );
}
