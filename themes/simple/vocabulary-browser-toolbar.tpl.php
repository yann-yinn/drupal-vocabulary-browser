<?php
/**
 * @file
 *
 * affiche le navigateur de vocabulaire.
 */
?>
<div id="vocabulary-browser-toolbar">
<ul>
<?php foreach($links as $link):?>
  <li>
    <?php print $link;?>
  </li>
<?php endforeach;?>
</ul>
<div class="clear"></div>
</div>
