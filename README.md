


## **HOW-TO: setup OpenHPC.** \
An Introduction to OpenHPC installation & configuration for HPC Ecosystems sites

Bryan Johnston

March 2019



---



## Introduction

This document will guide you through setting up a test environment for the HPC Ecosystems OpenHPC workshop.

This involves deploying an OpenHPC-ready Virtualbox VM using Vagrant. The sections of the guide include:



1. Installing & preparing the testbed VM through Vagrant
2. Installing & preparing OpenHPC software on VM

Although this solution has not been tested on hypervisors other than Virtualbox, Vagrant deployment should allow for the same results on any hypervisor of your preference.

The VM will be pre-configured with the standard software environment used in the hands-on workshop but can also be replicated at home, in your office, in a lab, or in the bath*.

The custom modifications include:



1. tmux ; vim ; git 
2. input.local (from OpenHPC) with custom edits which do not need to be replicated

_* results may vary_


## Install and prepare testbed VM through Vagrant


### Install Vagrant environment



1. Download & install Vagrant from [https://www.vagrantup.com/downloads.html](https://www.vagrantup.com/downloads.html) \


Download the HPC Ecosystems OpenHPC Vagrantfile



2. Navigate to the head / root of the directory that will host the VM for the workshop  \
(i.e. Go to the directory where you want to install the Vagrant VM and go from here)
3. Download the HPC Ecosystems Vagrantfile into this location: \
[https://github.com/brattex/hpc-ecosystems-openhpc/blob/master/Vagrantfile](https://github.com/brattex/hpc-ecosystems-openhpc/blob/master/Vagrantfile)
4. The following command will initialise the vagrant environment (and download the vagrant VM) - the entire process may take (many) several minutes depending on the internet connection. \

5. `vagrant up`
6. Once the process is completed you should be able to SSH into the VM
    1. `vagrant ssh`
    2. whatever SSH client to 127.0.0.1:2223
    3. vagrant::vagrant


## Install and prepare OpenHPC



7. Download your chosen OpenHPC image guide from: \
[https://openhpc.community/downloads/](https://openhpc.community/downloads/) \

8. Either directly on the VM or through the Vagrant shared directory, edit the base image template as follows: \

    4. The shared directory on the VM will be located at **/vagrant.**
    5. The shared directory on your host machine will be located in the head/root of the directory that hosts the VM, and will be the same location as **Vagrantfile**.
    6. The base image template is named **input.local** \

    7. Change all parameters after the "-" symbol in the configuration file
    8. **NOTE: You must carefully plan your system design before making changes to this file - a few <span style="text-decoration:underline;">minutes</span> of planning will save you <span style="text-decoration:underline;">days</span> of debugging! \
**
9. Follow the OpenHPC guide that you have selected in #7


## Basic Overview of HPC Design



*   [A basic overview of the planned layout of the OpenHPC "SMS" in relation to the WWW/WAN and HPC/LAN](https://docs.google.com/drawings/d/1dLHmKsdG1V1BkKHcwAN7WEJpGx49unMi7xDwe-L4FnQ/edit?usp=sharing)
    *   this will be useful in determining which ethX interface to use where!
