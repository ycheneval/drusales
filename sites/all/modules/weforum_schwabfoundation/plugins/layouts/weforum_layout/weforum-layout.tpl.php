<div class="panel-display weforum-layout" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel weforum top">
    <div class="inside"><?php print $content['top']; ?></div>
  </div>

  <div class="panel-panel weforum main">
    <div class="inside"><?php print $content['main']; ?></div>
  </div>

  <div class="panel-panel weforum sidebar">
    <div class="inside"><?php print $content['sidebar']; ?></div>
  </div>
</div>
