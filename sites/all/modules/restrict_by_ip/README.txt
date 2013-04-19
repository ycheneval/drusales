
DESCRIPTION
===========
Each user can be individually assigned an IP Addresses ranges from which they are allowed to login from.
Additionally, a global IP address range can be specified requiring any user to be within the required range to log in.

If they are not at a valid allowed ip address they cannot login.
Each time a user successfully logs in,  the roles are assigned according to their ip restriction placed on each role. So if a role is not allowed from a specific ip address, they will not have that role for their entire time logged in. This role based ip restriction only applies to roles that are NOT "annonymous user" or "authenticated user"
This module is designed to work with Drupal 6.x.

Installation
=====
1. Copy this directory to a suitable modules directory, such as 
     sites/all/modules
2. Enable the module at: Administer > Site building > Modules
3. Set the error page at: Administer > Site configuration > Restrict by IP > Restrict Login by IP
   This is for Login restriction only, and does not apply to the role restriction.
   
USAGE
=====
1.) All configuration can be managed from administration pages located at Administer > Site configuration > Restrict by IP
2.) Individual user IP restrictions may also be set in the 'Restrict by IP' fieldset located on the user add/edit form.
3.) IP restrictions are checked on every page load. If the IP is unauthorized, the user will be logged out and sent to specified 'error page'.
4.) Simply delete the value, and submit to remove a login or role IP restriction.

AUTHOR
======
Matt Rice (mrice [at] mattrice.org) 
Bobby Kramer (panthar1 [at] gmail.com)
James Gross (jamesrgross [at] gmail.com)
