(function($) {
    $.fn.extend({
        collapsiblePanel: function() {
            // Call the ConfigureCollapsiblePanel function for the selected element
            return $(this).each(ConfigureCollapsiblePanel);
        }
    });

})(jQuery);

function ConfigureCollapsiblePanel() {
    jQuery(this).addClass("ui-widget");

    // Wrap the contents of the container within a new div.
    jQuery(this).children().wrapAll("<div class='collapsibleContainerContent ui-widget-content'></div>");

    // Create a new div as the first item within the container.  Put the title of the panel in here.
    jQuery("<div class='collapsibleContainerTitle ui-widget-header'><div>" + jQuery(this).attr("title") + "</div></div>").prependTo(jQuery(this));

    // Assign a call to CollapsibleContainerTitleOnClick for the click event of the new title div.
    jQuery(".collapsibleContainerTitle", this).click(CollapsibleContainerTitleOnClick);
}

function CollapsibleContainerTitleOnClick() {
    // The item clicked is the title div... get this parent (the overall container) and toggle the content within it.
    jQuery(".collapsibleContainerContent", jQuery(this).parent()).slideToggle();
    
    var curTitle = jQuery(".collapsibleContainerTitle").html();
    if (curTitle.indexOf('Show') == -1) {
        jQuery(".collapsibleContainerTitle").html(curTitle.replace("Hide", "Show"));
    } else {
        jQuery(".collapsibleContainerTitle").html(curTitle.replace("Show", "Hide"));        
    }
}