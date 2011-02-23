<?php
/**
 * @file
 *
 * affiche le navigateur de vocabulaire.
 */
?>
<?php if ($items):?>
<div id="breadcrumb">
	<?php print theme('item_list', $items);?>
<div class="clear"></div>
</div>
<?php endif;?>
