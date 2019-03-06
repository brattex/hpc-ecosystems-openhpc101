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

7. Once you are inside your VM, the next step is to install the OpenHPC environment onto the VM...


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

An example walkthrough is available in this Google Doc:

[https://docs.google.com/document/d/e/2PACX-1vQ3YNvqfsWkAdW-LKKaWOR4Jw-PwqEWdCojg5O_WNoReYlytS0MLaTVZqVudJg0LS3Ky2z15yG6Pjpl/pub](https://docs.google.com/document/d/e/2PACX-1vQ3YNvqfsWkAdW-LKKaWOR4Jw-PwqEWdCojg5O_WNoReYlytS0MLaTVZqVudJg0LS3Ky2z15yG6Pjpl/pub)


## Basic Overview of HPC Design Choice



*   [A basic overview of the planned layout of the OpenHPC "SMS" in relation to the WWW/WAN and HPC/LAN](https://docs.google.com/drawings/d/1dLHmKsdG1V1BkKHcwAN7WEJpGx49unMi7xDwe-L4FnQ/edit?usp=sharing)
    *   this will be useful in determining which ethX interface to use where! \



## Other References



*   CHPC OpenHPC presentation slides
    *   [https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing](https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing)
