<?php
/**
 * @file
 *
 * affiche le navigateur de vocabulaire.
 */
?>

<ul id="vocabularies">
<?php foreach($links as $link):?>
<li> <?php print $link;?> </li>
<?php endforeach;?>
</ul>
