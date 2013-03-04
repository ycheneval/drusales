/**
  * Placeholder plugin for IE
  */
(function ($) {

  Drupal.behaviors.script = {
    attach: function (context, settings) {
      // if ($.fn.mobileMenu) {
      //   $('ol#id').mobileMenu({
      //     switchWidth: 768,                   // width (in px to switch at)
      //     topOptionText: 'Choose a page',     // first option text
      //     indentString: '&nbsp;&nbsp;&nbsp;'  // string for indenting nested items
      //   });
      // }

      $('html').removeClass('no-js').addClass('js');

      // Run Mathias Bynens jQuery placeholder plugin
      if ($.fn.placeholder) {
        $('input, textarea').placeholder();
      }

      // BUILD MENUS
      if ($('#touch-menu').length == 0) {
        $menu = $("<nav id='touch-menu' class='generated touch hidden'><nav>");
        $menu_main = $("#main-menu").clone().attr("id", "touch-main-menu");
        $menu_utility = $("#block-menu-menu-utility-menu .menu").clone();
        $hub_search = $(".pane-weforum-hub-search").clone().removeClass("pane-weforum-hub-search").addClass("touch-pane-weforum-hub-search");
        $language_drop = $("#block-lang-dropdown-language").clone().attr("id", "touch-block-lang-dropdown-language");
        $social_links = $("#block-weforum-social-weforum-social-links").clone().attr("id", "touch-weforum-social-weforum-social-links");
        $menu.html($menu_main)
          .append($menu_utility)
          .append($hub_search)
          .append($language_drop)
          .append($social_links);
        $("[role=banner]").prepend($menu);
        $touch_menu_btn = $("<div id='touch-menu-btn' class='ss-icon'>List</div>")
        $("[role=banner]").prepend($touch_menu_btn);
        $touch_menu_btn.toggle(
          function () {
            $menu.removeClass("hidden");
            $(this).addClass("close").html("Close");
          },
          function () {
            $menu.addClass("hidden");
            $(this).removeClass("close").html("List");
          }
        );
      }
    }
  };

}(jQuery));
