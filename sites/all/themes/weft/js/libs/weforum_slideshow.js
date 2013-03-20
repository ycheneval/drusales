(function ($) {

Drupal.behaviors.weforum_slideshow = {
  attach: function (context, settings) {
    settings.weforum_slideshow = settings.weforum_slideshow || {index: 1};
//    console.log("hello world");
    var $context = $(context);
    // Hide all the children first.
    $context.find('.view-content .weforum-slideshow-item.views-row:not(:first-child)').hide();

    // Run this through each, in case they choose later to add multiple slideshows to a page.
    $context.find('.view.weforum-slideshow').once('weforum-slideshow').each(function () {
      var $slideshow = $(this);
      var elements = $slideshow.find('.weforum-slideshow-item').size();
      if (elements > 1) {
        var pager = '<div class="weforum-slideshow-pager"><span class="item-prev">prev</span>';
//        var pager = '<div class="weforum-slideshow-pager"><span class="item-prev"></span>';     // YCH fix
        for (var i = 1; i <= elements; i++) {
          pager += '<span class="pager-button item-' + i + '">' + i + '</span></span>';
//          pager += '<span class="pager-button item-' + i + '"></span></span>';  // YCH fix
        }
        pager += '<span class="item-next">next</span></div>';
//        pager += '<span class="item-next"></span></div>';   // YCH fix   
        $slideshow.prepend(pager);
      }
      $('.weforum-slideshow-pager .item-' + settings.weforum_slideshow.index).addClass('active');

      // Cycle.
      setTimeout(function () {
        feature_cycle();
      }, 10000);

      $slideshow.find('.weforum-slideshow-pager span').click(function () {
        // Find out what they clicked
        var $span = $(this);
        var button = $span.attr('class').match(/item-(.*)/)[1];
        if (button == 'prev') {
          // Jump to prev item, if we hit the begining just wrap around.
          settings.weforum_slideshow.index--;
          if (settings.weforum_slideshow.index == 0) {
            settings.weforum_slideshow.index = elements;
          }
        }
        else if (button == 'next') {
          // Jump to next item, if we hit the begining just wrap around.
          settings.weforum_slideshow.index++;
          if (settings.weforum_slideshow.index == elements + 1) {
            settings.weforum_slideshow.index = 1;
          }
        }
        else if (button) {
          // Assume that it's a number and just jump to that row.
          settings.weforum_slideshow.index = button;
          // Give the button itself an active class.
          $span.addClass('active');
        }
        $span
          .siblings()
          .removeClass('active')
          .filter('.item-' + settings.weforum_slideshow.index)
          .addClass('active');
        $slideshow
          .find('.weforum-slideshow-item')
          .hide()
          .filter('.views-row-' + settings.weforum_slideshow.index).show();
      });
    });
  }
};

/**
 * Do a timed cycle.
 */
function feature_cycle() {
  var next = Drupal.settings.weforum_slideshow.index + 1;
  var $slideshow = $('.view.weforum-slideshow').find('.views-row').hide().end();
  var $nextSlide = $slideshow.find('.views-row-' + next);
  if ($nextSlide.size() == 0) {
    next = 1;
    $nextSlide = $slideshow.find('.views-row-' + next);
  }
  $nextSlide.show();
  $('.weforum-slideshow-pager span')
    .removeClass('active')
    .filter('.item-' + next)
    .addClass('active');
  Drupal.settings.weforum_slideshow.index = next;
  // And repeat.
  setTimeout(function () {
    feature_cycle();
  }, 10000);
}

}(jQuery));
