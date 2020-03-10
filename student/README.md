# https://medium.com/@atulsingh0/git-use-sparse-checkout-pull-specific-folder-from-repository-1091b2da52bf

* navigate to your preferred start location (e.g. ~/openhpc-handson/)
* mkdir ~/openhpc-handson
* cd ~/openhpc-handson
* git init
* git remote add origin https://github.com/brattex/hpc-ecosystems-openhpc101.git
* git checkout -b 'student_branch'
* git config core.sparsecheckout true
* echo 'student' >> .git/info/sparse-checkout
* git pull origin master
