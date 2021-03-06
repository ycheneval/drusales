/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
function fire_search() {
    var columns = [];
    columns[0] = jQuery('#edit-field-full-name-value').val();
    columns[1] = jQuery('#edit-field-org-public-name-value').val();
    columns[2] = jQuery('#edit-field-area-of-impact-value').val();
    columns[3] = jQuery('#edit-field-sector-value').val();
    columns[4] = jQuery('#edit-field-model-value').val();
    
    jQuery('.views-table').trigger('search', [columns]);            
    return columns;
}

    (function($){
        var table = '';
//        console.log($('.views-table'));
//        $('.tablesorter-childRow td').hide();
        $('.views-table').tablesorter({ 
            theme : 'blue',
            widthFixed: false,
            widgets: ['zebra', 'filter', 'resizable'],
            headers: {  2: { sorter: false },
                    3: { sorter: false }
            },
            sortList: [[1,0]]
        });

        // Hide filter row and "apply" button
        $('.tablesorter-filter-row').addClass('hidden');
        $('.views-submit-button').addClass('hidden');
        
        $('.totalNbInList').text($('input[name^=regform]').length);

        $('#edit-field-full-name-value,#edit-field-org-public-name-value').keyup(function() {
            fire_search();
        });

        $('#edit-field-area-of-impact-value,#edit-field-sector-value,#edit-field-model-value').change(function() {
            fire_search();
        });

        // Add a small open/close thing
//        $( ".views-exposed-form" ).attr("title", "Filters");
        $(".views-exposed-form").attr("title", "Hide filters list");
        $(".views-exposed-form").collapsiblePanel();
//        $(".views-exposed-form").slideToggle();

        // Make the visible area of impacts comma separated.
        // We need a client-side solution since some AoI will be in the HTML
        // but kept hidden (for filtering purpose)
        $('.view-test .views-field-field-area-of-impact span[data-priority-name="High"]').prevAll('span[data-priority-name="High"]').append(', ');


})(jQuery);

