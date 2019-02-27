# hpc-ecosystems-openhpc
##CHPC's HPC Ecosystems OpenHPC repository

https://github.com/openhpc/ohpc


<!----- Conversion time: 0.689 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β15
* Wed Feb 27 2019 03:51:13 GMT-0800 (PST)
* Source doc: https://docs.google.com/open?id=1Aeez_p2ebRwVGbIh5KVImHIzmNWfE_P2f5M2tK1jAIg
* This is a partial selection. Check to make sure intra-doc links work.

WARNING:
You have 3 H1 headings. You may want to use the "H1 -> H2" option to demote all headings by one level.

----->


<p style="color: red; font-weight: bold">>>>>>  gd2md-html alert:  ERRORs: 0; WARNINGs: 1; ALERTS: 0.</p>
<ul style="color: red; font-weight: bold"><li>See top comment block for details on ERRORs and WARNINGs. <li>In the converted Markdown or HTML, search for inline alerts that start with >>>>>  gd2md-html alert:  for specific instances that need correction.</ul>

<p style="color: red; font-weight: bold">Links to alert messages:</p>
<p style="color: red; font-weight: bold">>>>>> PLEASE check and correct alert issues and delete this message and the inline alerts.<hr></p>



# HOWTO: HPC Ecosystems OpenHPC Workshop setup

Bryan Johnston

March 2019



---



# Introduction

This document will guide you through setting up a test environment for the HPC Ecosystems OpenHPC workshop.

The steps will install an OpenHPC-ready Virtualbox VM using Vagrant. 

Although this has not been tested on other hypervisors, Vagrant deployment should allow for the same results on any hypervisor of your preference.

The VM will be pre-configured with the standard software environment used in the hands-on workshop but can also be replicated at home, in your office, in a lab, or in the bath*.

_* results may vary_




# Install and prepare VM through Vagrant


## Install Vagrant



1. Download & install Vagrant from [https://www.vagrantup.com/downloads.html](https://www.vagrantup.com/downloads.html) \


Download the HPC Ecosystems Vagrantfile



2. Navigate to the head / root of the directory that will host the VM for the workshop  \
(i.e. Go to the directory where you want to install the Vagrant VM and go from here)
3. Download the HPC Ecosystems Vagrantfile into this location: \
[https://github.com/brattex/hpc-ecosystems-openhpc/blob/master/Vagrantfile](https://github.com/brattex/hpc-ecosystems-openhpc/blob/master/Vagrantfile)
4. The following command will initialise the vagrant environment (and download the vagrant VM) - the entire process may take (many) several minutes depending on the internet connection. \

5. `vagrant up`
6. Once the process is completed you should be able to SSH into the VM
    1. `vagrant ssh`
    2. whatever SSH client to 127.0.0.1:2223
    3. vagrant::vagrant \



# Install and prepare OpenHPC



7. Download your chosen OpenHPC image guide from: \
[https://openhpc.community/downloads/](https://openhpc.community/downloads/) \

8. Either directly on the VM or through the Vagrant shared directory, edit the base image template as follows: \
 \
The shared directory on the VM will be located at **/vagrant. \
**The shared directory on your host machine will be located in the head/root of the directory that hosts the VM, and will be the same location as **Vagrantfile**. \
The base image template is named **input.local** \

    4. Change all parameters after the "-" symbol in the configuration file
    5. **NOTE: You must carefully plan your system design before making changes to this file - a few <span style="text-decoration:underline;">minutes</span> of planning will save you <span style="text-decoration:underline;">days</span> of debugging! \
**

<!-- Docs to Markdown version 1.0β15 -->
