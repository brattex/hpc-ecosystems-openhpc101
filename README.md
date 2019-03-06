## **HOW-TO: setup OpenHPC.** \
An Introduction to OpenHPC installation & configuration for HPC Ecosystems sites

Bryan Johnston

March 2019



---



## QUICKSTART

[Jump to the hands-on practical steps by clicking here.](#bookmark=id.r5m2h0l5cm7x) \
(if link does not work, scroll to "Install and prepare testbed VM through Vagrant")


## Introduction

This document will guide you through setting up a test environment for the HPC Ecosystems OpenHPC workshop.

This involve deploying an OpenHPC-ready Virtualbox VM using Vagrant. The sections of the guide include:



1. Installing & preparing the testbed VM through Vagrant
2. Installing & preparing OpenHPC software on VM

Although this solution has not been tested on hypervisors other than Virtualbox, Vagrant deployment should allow for the same results on any hypervisor of your preference.

The VM will be pre-configured with the standard software environment used in the hands-on workshop but can also be replicated at home, in your office, in a lab, or in the bath*.

The custom modifications include:



1. tmux ; vim ; git 
2. input.local (from OpenHPC) with custom edits which do not need to be replicated

_* results may vary_


## Useful addenda & Tips


### Workload Time



*   Download speeds aside, it will take approx. **10 to 15 minutes** to complete the Vagrant installation and Virtualbox VM deployment.
*   The actual time to configure the OpenHPC input.local and run through the guide will vary depending on
    *   Your willingness to read the guide thoroughly before executing each step (HIGHLY RECOMMENDED)
    *   Your familiarity with the instruction syntax and commands used
    *   Your familiarity with the HPC design being implemented here
    *   Your willingness to plan before executing (looking before you leap, crawl before you walk, read before you write, live before you die, etc.)


## Install and prepare testbed VM through Vagrant


### Install Vagrant environment



1. Download & install Vagrant from [https://www.vagrantup.com/downloads.html](https://www.vagrantup.com/downloads.html) \


Download the HPC Ecosystems OpenHPC SMShost Vagrantfile



2. Navigate to the head / root of the directory that will host the VM for the workshop  \
(i.e. Go to the directory where you want to install the Vagrant VM and go from here, for example **/openhpc/smshost/**)
3. Download the HPC Ecosystems SMShost **Vagrantfile **into this location: \
[https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/Vagrantfile](https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/Vagrantfile) (note, save file as **Vagrantfile** with no file extensions)
4. The following command will initialise the vagrant environment (and download the vagrant VM) - the entire process may take (many) several minutes depending on the internet connection. \

5. `vagrant up`
    1. This will read the Vagrantfile parameters and ...
    2. Create the Virtualbox (or other Hypervisor) framework (such as vCPUs, RAM, NIC's, etc.) then ...
    3. Download the CentOS image and install it onto the VM. 
    4. Once the VM is booted up for the first time, a Vagrant shell script will run a **yum update** and also some **yum install** commands, all "behind-the-scenes". \

6. Once the process is completed you should be able to SSH into the VM either through (a) or (b) below.
    5. `vagrant ssh`
    6. whatever SSH client to 127.0.0.1:2223
    7. The username and password is \
vagrant::vagrant \

7. Once you are inside your VM environment, the next step is to install the OpenHPC environment onto the VM...


## Install and prepare OpenHPC SMS Host



8. Download your chosen OpenHPC image guide from: \
[https://openhpc.community/downloads/](https://openhpc.community/downloads/) \

    8. _For the sake of illustrations in this guide, we will be using CentOS 7.5 x86_64 with Warewulf + PBS Professional. \
[https://github.com/openhpc/ohpc/releases/download/v1.3.6.GA/Install_guide-CentOS7-Warewulf-PBSPro-1.3.6-x86_64.pdf](https://github.com/openhpc/ohpc/releases/download/v1.3.6.GA/Install_guide-CentOS7-Warewulf-PBSPro-1.3.6-x86_64.pdf) \
_
    9. _It is a useful approach to store this PDF in the **/vagrant **shared directory \
_
        1. The shared directory _on the VM_ is located at **/vagrant. \
**
        2. The shared directory _on your host machine_ is located in the head/root of the directory structure that hosts the VM, and will be the same path as the location for the **Vagrantfile **you downloaded earlier.. \
_(e.g. /openhpc/smshost/) \
_
9. Either _directly on the VM_ or _through the Vagrant shared directory_, edit the base image template **input.local**. _ \
_
    10. The base image template is named **input.local **and is downloaded from OpenHPC Docs or from the git repository below (it is recommended to download the git repository version because this has been modified slightly for HPC Ecosystems sites)
        3. download **input.local **from the link below and save it in **/vagrant **(which is accessible in the VM): [https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/input.local](https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/input.local) \

    11. Change appropriate parameters after the "-" symbol in the configuration file
        4. You do not need to be concerned about uncommenting what is not needed for your particular environment; this base image template is used by **recipe.sh** for automated installations and will check all the parameters before installing anything. \

        5. In our case, we are doing the steps run in **recipe.sh** manually, and only the relevant global parameters for your chosen configuration will be used. \

    12. **NOTE: You must carefully plan your system design before making changes to this file - a few <span style="text-decoration:underline;">minutes</span> of planning will save you <span style="text-decoration:underline;">days</span> of debugging! \
**
10. Follow the OpenHPC guide that you have selected from [https://openhpc.community/downloads/](https://openhpc.community/downloads/) (above)




## OpenHPC Example walkthrough


### The following walkthrough is using the CentOS 7.5 x86_64 Warewulf + PBS Professional guide:



1. edit **input.local** and update the following parameters
    1. sms_name="${sms_name:-smshost}"
    2. sms_ip="${sms_ip:-10.10.10.10}"
    3. sms_eth_internal="${sms_eth_internal:-eth1}"
    4. internal_netmask="${internal_netmask:-255.255.0.0}"
    5. ntp_server="${ntp_server:-0.centos.pool.ntp.org}"
    6. **bmc_username="${bmc_username:-unknown}"**
    7. **bmc_password="${bmc_password:-unknown}"**
    8. eth_provision="${eth_provision:-eth1}"
    9. num_computes="${num_computes:-2}"
    10. c_name[0]=c1
    11. c_name[1]=c2
    12. c_ip[0]=10.10.10.100
    13. c_ip[1]=10.10.10.101
    14. c_mac[0]=00:1a:2b:3c:4f:56
    15. c_mac[1]=00:1a:2b:3c:4f:56
    16. c_bmc[0]=10.16.1.1
    17. c_bmc[1]=10.16.1.2
    18. compute_regex="${compute_regex:-compute*}"
    19. compute_prefix="${compute_prefix:-compute}" \

2. The Base Operating System (BOS) for the SMS host is already installed by vagrant. The compute node images will be booted via PXE diskless from the SMS host. 
    20. Complete all steps in section 2, namely:
        1. echo ${sms_ip} ${sms_name} >> /etc/hosts  
        2. systemctl disable firewalld  
        3. systemctl stop firewalld   \

3. Install OpenHPC Components
    21. Install the **ohpc-release** package, which will enable the OpenHPC repository for local use, as well as enabling CentOS-7-Base* and EPEL 7 yum repositories.
    22. Although there is an automated installation template **recipe.sh** that is available for a hands-off automated installation, for the purpose of learning, all commands will be copy/paste from the guide. In a production environment it would be convenient to use the script.
    23. Install the OHPC base packages and OHPC warewulf packages and enable NTP as per the guide. \
 \
_Note: Using ipmitool is advisable in a production environment but in this virtual tutorial ipmitool will not be configured._
    24. Install PBS Pro
    25. InfiniBand will not be installed.
    26. Omnipath will not be installed.
    27. Configure Warewulf (WW) to provision compute nodes on the internal interface (**eth1**).
    28. Define _compute_ image for provisioning over PXE
        4. configure the WW image root
            1. $CHROOT is configured to point to **/opt/ohpc/admin/images/centos7.5** which will host the base image for the compute nodes. In practice, you may have multiple images stored in different directories. For this tutorial we are only using the one image.
        5. Add OpenHPC base compute components to image and configure client DNS settings
            2. note the use of **--installroot=$CHROOT **with yum will install components to the PXE image we are constructing, instead of to the local SMS host. This will later mean that all machines booting from this image will have the packages installed.
        6. Customize system configuration
        7. We will not add additional customizations in this basic tutorial although in production you may wish to add several of the options presented in 3.8.4 \

        8. We will be using the SMS host (provisioning server)'s user credentials on the compute nodes, so we will import the **/etc/passwd, group, shadow** files to the client image with **wwsh file import**. \

    29. Finalise provisioning configuration
        9. Assemble the bootstrap image with **wwbootstrap `uname -r`  **
        10. Assemble VNFS image (this will take the CHROOT environment and create a VNFS capsule for PXE booting).
        11. 


## Basic Overview of HPC Design Choice



*   [A basic overview of the planned layout of the OpenHPC "SMS" in relation to the WWW/WAN and HPC/LAN](https://docs.google.com/drawings/d/1dLHmKsdG1V1BkKHcwAN7WEJpGx49unMi7xDwe-L4FnQ/edit?usp=sharing)
    *   this will be useful in determining which ethX interface to use where! \



## Other References



*   CHPC OpenHPC presentation slides
    *   [https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing](https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing)
