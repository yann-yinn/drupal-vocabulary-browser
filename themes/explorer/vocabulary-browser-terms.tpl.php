<?php
/**
 * @file
 *
 * affiche le navigateur de vocabulaire.
 */
?>

<?php if ($terms):?>
<ul id="terms">
<?php foreach($terms as $term):?>
  <li>
    <?php print $term->is_new ? '<div id="term-new">Nouveau</div>' : '';?>
    <?php print $term->view_link;?>
    <?php print $term->edit_link;?>
  </li>
<?php endforeach;?>
<?php else :?>
  Il n'y a aucune terme enfant pour <strong><?php print $term_current->name ;?></strong><br />
  Cliquer sur "Ajouter un nouveau terme" pour ajouter un terme.
</ul>
<div class="clear"></div>
<?php endif;?>
