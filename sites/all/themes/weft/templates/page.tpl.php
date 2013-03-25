<?php
// $Id$

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

  <div id="page-wrapper"></div><div id="page">

    <header role="banner" class="clearfix page-banner">

      <?php if ($utility = render($page['utility'])): ?>
        <div id="utility-bar">
          <div class="container">
            <?php print $utility; ?>
          </div>
        </div>
      <?php endif; ?>

      <?php if ($search = render($page['search'])): ?>
        <div id="utility-bar-search">
          <div class="container">
            <?php print $search; ?>
          </div>
        </div>
      <?php endif; ?>


      <?php if ($site_name || $site_slogan) { ?>
        <div class="line-height-110">
        <?php if ($logo) { ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php } ?>
        <hgroup id="name-and-slogan">
          <?php if ($site_name){ ?>
            <h1 id="site-name">
                <div class="line-height-110"><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a></div>
            </h1>
          <?php } ?>

        </hgroup>
        </div><!-- /#name-and-slogan -->
        <?php if ($site_slogan): ?>
          <p id="site-slogan"><?php print $site_slogan; ?></p>
        <?php endif; ?>
      <?php } 
      else { ?>
        <?php if ($logo) { ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php } ?>
    <?php } ?>

      <?php print render($page['header']); ?>

    </header> <!-- /header -->

    <?php print $messages; ?>

    <?php if ($main_menu): ?>
      <nav role="navigation">
        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
      </nav> <!-- /nav -->
    <?php endif; ?>

    <div id="main-wrapper" class="clearfix">

      <?php print render($page['sidebar_first']); ?>

      <div role="main">
        <?php print render($page['highlighted']); ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($subheader = render($page['subheader'])): ?><section id="bottom-bar"><div class="container"><?php print $subheader ?></div></section><?php endif; ?>
        <?php if ($breadcrumb): ?><nav id="breadcrumb"><?php print $breadcrumb; ?></nav><?php endif; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links = render($action_links)): ?><ul class="action-links"><?php print $action_links; ?></ul><?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div> <!-- /main -->

      <?php print render($page['sidebar_second']); ?>

    </div> <!-- /#main -->

    <?php print render($page['footer']); ?>

  </div> <!-- /#page -->
