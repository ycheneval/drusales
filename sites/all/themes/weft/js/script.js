(function ($) {

  Drupal.behaviors.script = {
    attach: function (context, settings) {

      $('html').removeClass('no-js').addClass('js');

      // BUILD MENUS
      if ($('#touch-menu').length == 0) {
        $menu = $("<div id='touch-menu' class='generated touch hidden'><div>");
        $menu_main = $("#main-menu").clone().attr("id", "touch-main-menu");
        $menu_utility = $("#block-menu-menu-utility-menu .menu").clone();
        $hub_search = $(".pane-weforum-hub-search").clone().removeClass("pane-weforum-hub-search").addClass("touch-pane-weforum-hub-search");
        $language_drop = $("#block-lang-dropdown-language").clone().attr("id", "touch-block-lang-dropdown-language");
        $social_links = $("#block-weforum-social-weforum-social-links").clone().attr("id", "touch-weforum-social-weforum-social-links");
        $menu.html($menu_main).append($menu_utility).append($hub_search).append($language_drop).append($social_links);
        $(".page-banner").prepend($menu);
        $touch_menu_btn = $("<div id='touch-menu-btn' class='ss-icon'>&#xED50;</div>")
        $(".page-banner").prepend($touch_menu_btn);
        $touch_menu_btn.toggle(
          function () {
            $menu.removeClass("hidden");
            $(this).addClass("close").html("&#x2421;");
          },
          function () {
            $menu.addClass("hidden");
            $(this).removeClass("close").html("&#xED50;");
          }
        );
      }
    }
  };

}(jQuery));
