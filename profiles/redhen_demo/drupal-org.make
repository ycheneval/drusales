api = 2
core = 7.x

; defaults
defaults[projects][subdir] = "contrib"

; Standard Contrib Modules
projects[] = addressfield
projects[] = admin_menu
projects[] = ctools
projects[] = diff
projects[] = devel
projects[] = features
projects[] = r4032login
projects[] = strongarm
projects[] = token
projects[] = views
projects[] = entityreference

projects[entity][version] = 1.0
projects[relation][version] = 1.0-rc3
projects[message][version] = 1.7
projects[libraries][version] = 2.0

; Modules we want to checkout to work on
projects[registration][type] = "module"
projects[registration][download][type] = "git"
projects[registration][download][url] = "http://git.drupal.org/project/registration.git"
projects[registration][download][branch] = "7.x-1.x"

; RedHen Module Suite
projects[redhen][type] = "module"
projects[redhen][download][type] = "git"
projects[redhen][download][url] = "http://git.drupal.org/project/redhen.git"
projects[redhen][download][branch] = "7.x-1.x"
projects[redhen][subdir] = "redhen"

projects[redhen_membership][type] = "module"
projects[redhen_membership][download][type] = "git"
projects[redhen_membership][download][url] = "http://git.drupal.org/project/redhen_membership.git"
projects[redhen_membership][download][branch] = "7.x-1.x"
projects[redhen_membership][subdir] = "redhen"

; Themes
projects[zen][version] = 5.x-dev
projects[zen][subdir] = ""

projects[poultry][type] = "theme"
projects[poultry][download][type] = "git"
projects[poultry][download][url] = "http://git.drupal.org/project/poultry.git"
projects[poultry][download][branch] = "7.x-1.x"
projects[poultry][subdir] = ""
