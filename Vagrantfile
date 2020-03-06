# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://vagrantcloud.com/search.

  config.vm.box = "bento/centos-7.7"
  config.vm.box_version = "202002.04.0"  
  config.vm.hostname = "ecosystems_sms"
  
  #config.vm.post_up_message = "HPC Ecosystems \r\n user:vagrant password:vagrant"
  
  #### MESSAGE_BEGIN
  config.vm.post_up_message = <<-MESSAGE
    Vagrant VM configuration complete!
	
      You now have a 3-node stellar cluster running within vagrant.

    This includes the following vms:
      - ecosystems_sms: the SMS host for OpenHPC (unless defined in setenv.c)
	  
      - core_vm2: a second stellar-core validator
      - core_vm3: a third stellar-core validator

    To see the logs for your new nodes run:
        vagrant ssh <NODE> -c 'sudo tailf /var/log/upstart/stellar-core.log'

    To query status (or other http endpoint commands) run:
        vagrant ssh <NODE> -c 'curl http://localhost:39132/info'
  
    To access a ledger database run:
        vagrant ssh <NODE> -c 'sudo -iustellar psql'

  MESSAGE
  #### MESSAGE_END
	
  #config.vm.box = "bento/centos-7.6"
  #config.vm.box_version = "201812.27.0"
  #config.vm.box = "bento/centos-7.5"
#  config.vm.box_version = "201811.25.0"

  # Disable automatic box update checking. If you disable this, then
  # boxes will only be checked for updates when the user runs
  # `vagrant box outdated`. This is not recommended.
  # config.vm.box_check_update = false

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # NOTE: This will enable public access to the opened port
  # config.vm.network "forwarded_port", guest: 80, host: 8080
config.vm.network "forwarded_port", guest: 22, host: 2229, id: "ssh"

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine and only allow access
  # via 127.0.0.1 to disable public access
  # config.vm.network "forwarded_port", guest: 80, host: 8080, host_ip: "127.0.0.1"

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"
config.vm.network "private_network", ip: "10.10.10.10"
  
  # Create a public network, which generally matched to bridged network.
  # Bridged networks make the machine appear as another physical device on
  # your network.
  # config.vm.network "public_network"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  # config.vm.synced_folder "../data", "/vagrant_data"
  # config.vm.synced_folder "

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  config.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
    vb.gui = true
    # Customize the amount of memory on the VM:
    vb.memory = "1024"
	# set the VM host to dual core
	vb.cpus = 2
		
	# rename from default (containing folder+timestamp)
	vb.name = "ecosystems_sms"
	
	# set host CPU cap to 50% of host machine
	vb.customize ["modifyvm", :id, "--cpuexecutioncap", "50"]
  end

  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.
  # config.vm.provision "shell", inline: <<-SHELL
  #   apt-get update
  #   apt-get install -y apache2
  # SHELL

#  config.vm.provision "shell", inline: <<-SHELL
#	sudo yum install vim git tmux screen -y
	#sudo yum update -y --exclude=kernel*
    
	#      build-essential git pkg-config zip unzip software-properties-common \
	#      python-pip python-dev \
	#      libgmp-dev gcc-multilib valgrind openmpi-bin openmpi-doc libopenmpi-dev \
	#      portmap rpcbind libcurl4-openssl-dev bzip2 imagemagick libmagickcore-dev \
	#      libssl-dev libffi6 libffi-dev llvm

	#    sudo pip install --upgrade pip
	#    sudo pip install --upgrade requests future cryptography pyopenssl ndg-httpsclient #pyasn1 nelson
#  SHELL
  # more tips: https://www.vagrantup.com/docs/provisioning/shell.html "heredoc"
  config.vm.provision "shell" do |s|
	s.inline = "sudo yum install vim git tmux screen -y"
  end

  config.vm.define "client01" do |client01|
	client01.vm.hostname = "ecosystems_sms"
	client01.vm.network "private_network", ip: "10.10.10.101"
	
	client01.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
	  vb.gui = true
    # Customize the amount of memory on the VM:
      vb.memory = "512"
	# set the VM host to dual core
	  vb.cpus = 2

	# rename from default (containing folder+timestamp)
      vb.name = "client01"
	
	# set host CPU cap to 50% of host machine
	  vb.customize ["modifyvm", :id, "--cpuexecutioncap", "25"]
  end	
	end #client01
	
## playing around with autoscale
#  config.vm.provider 'virtualbox' do |vb|
#      vb.gui = true
#      vb.customize ['setextradata', :id, 'GUI/ScaleFactor', '1.25']
#    end

end
