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


})(jQuery);

