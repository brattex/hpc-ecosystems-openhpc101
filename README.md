---


---

<h1 id="how-to-setup-openhpc.">HOW-TO: setup OpenHPC.</h1>
<h3 id="an-introduction-to-openhpc-installation--configuration"><em>An Introduction to OpenHPC installation &amp; configuration</em></h3>
<p>Bryan Johnston<br>
20200203</p>
<p><em>This guide was initially produced for  HPC Ecosystems sites.</em></p>
<h2 id="quickstart">QUICKSTART</h2>
<p><a href="#bookmark=id.r5m2h0l5cm7x">Jump to the hands-on practical steps by clicking here.</a></p>
<p>(if link does not work, scroll to “Install and prepare testbed VM through Vagrant”)</p>
<h3 id="lab-preparation----introduction">Lab Preparation – Introduction</h3>
<p>This section provides a step-by-step guide for  setting up the Virtual Lab environment. The Virtual Lab will configure <strong>three lightweight virtual machines</strong> using the <strong>Virtualbox</strong> hypervisor.</p>
<pre><code>!! IMPORTANT !!

This guide uses VIRTUALBOX for the virtual lab environment.
VAGRANT is used to manage the Virtualbox VM's.
YOU DO NOT NEED VIRTUALBOX OR VAGRANT FOR THE FINAL HPC DEPLOYMENT.
Vagrant and Virtualbox are used for the TRAINING LAB.
</code></pre>
<p>This training involves deploying an <strong>OpenHPC-ready Virtualbox VM using Vagrant</strong>. The sections of the guide include:</p>
<ol>
<li>Installing &amp; preparing the testbed VM through Vagrant</li>
<li>Installing &amp; preparing OpenHPC software on VM</li>
</ol>
<p>Although this solution has not been tested on hypervisors other than Virtualbox, Vagrant deployment should allow for the same results on any hypervisor of your preference (e.g. VMware).</p>
<p>The VM will be pre-configured with the standard software environment used in the hands-on workshop but can also be replicated at home, in your office, in a lab, or in the bath*.</p>
<p>The custom modifications include:</p>
<ol>
<li>tmux ; vim ; git</li>
<li>input.local (from OpenHPC) with custom edits which do not need to be replicated</li>
<li>setenv.c</li>
</ol>
<p><em>* results may vary</em></p>
<h2 id="useful-addenda--tips">Useful addenda &amp; Tips</h2>
<h3 id="workload-time">Workload Time</h3>
<ul>
<li>Download speeds aside (the CentOS image is approx. 600MB), it will take approx. <strong>10 to 15 minutes</strong> to complete the Vagrant installation and Virtualbox VM deployment.</li>
<li>The actual time to configure the OpenHPC input.local and run through the guide will vary depending on
<ul>
<li>Your willingness to read the guide thoroughly before executing each step (HIGHLY RECOMMENDED)</li>
<li>Your familiarity with the instruction syntax and commands used</li>
<li>Your familiarity with the HPC design being implemented here</li>
<li>Your willingness to plan before executing (looking before you leap, crawl before you walk, read before you write, live before you die, etc.)</li>
</ul>
</li>
</ul>
<pre><code>TIP: READ the instructions carefully!
Make sure you understand them before executing them - if you make a mistake, you need to know what happened so you can fix it!
</code></pre>
<h2 id="install-and-prepare-testbed-vm-through-vagrant">Install and prepare testbed VM through Vagrant</h2>
<h3 id="install-virtualbox">Install Virtualbox</h3>
<p>Virtualbox is used to run the virtual cluster. We will concentrate on deploying the Management server as a VM (but it can also be used as the final solution, but this is mostly for interest and not recommended as a long-term solution). <strong><em>This is not required for the final HPC system.</em></strong></p>
<ul>
<li><a href="https://www.virtualbox.org/wiki/Downloads">https://www.virtualbox.org/wiki/Downloads</a></li>
</ul>
<h3 id="install-vagrant-environment">Install Vagrant environment</h3>
<p>Vagrant is used to manage the Virtualbox VM - it will configure the VM to precise specifications for the workshop and makes sure everyone has the same setup. <strong><em>This is not required for the final HPC system.</em></strong></p>
<ol>
<li>Download &amp; install Vagrant from <a href="https://www.vagrantup.com/downloads.html">https://www.vagrantup.com/downloads.html</a></li>
</ol>
<pre><code>TIP: There are two options for obtaining the testbed VM settings:
o Use git to clone the HPC Ecosystems OpenHPC repository (recommended)
o Directly copy the Vagrant configuration files
</code></pre>
<h3 id="option-1-recommended-clone-git-repository-you-must-have-git-installed">Option 1 (RECOMMENDED): Clone git repository (YOU MUST HAVE GIT INSTALLED)</h3>
<p>This option will keep all updates or changes synchronised with your system. This is the best long-term solution for the workshop.</p>
<ol>
<li>Install git
<ol>
<li>gitbash for Windows <a href="https://gitforwindows.org/">https://gitforwindows.org/</a></li>
<li>git for Linux</li>
<li>git for MacOS</li>
</ol>
</li>
<li>(from location of git root - where you want to run the workshop files on your system; e.g. **\users\myname\desktop\openhpcworkshop**)</li>
<li>git init</li>
<li>git remote add origin <a href="https://github.com/brattex/hpc-ecosystems-openhpc101.git">https://github.com/brattex/hpc-ecosystems-openhpc101.git</a></li>
<li>git pull origin master</li>
</ol>
<h3 id="option-2-download-the-hpc-ecosystems-openhpc-smshost-vagrantfile">Option 2: Download the HPC Ecosystems OpenHPC SMShost Vagrantfile</h3>
<p>This option will not use git for the workshop. This will not synchronise with the files on the OpenHPC repository. You will need to copy the files you need for the workshop to your PC.</p>
<ol>
<li>
<p>Navigate to the head / root of the directory that will host the VM for the workshop</p>
<p>(i.e. Go to the directory where you want to install the Vagrant VM and go from here, for example <strong>/openhpc/smshost/</strong>)</p>
</li>
<li>
<p>Download the HPC Ecosystems SMShost <strong>Vagrantfile</strong> into this location:</p>
<p><a href="https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/Vagrantfile">https://raw.githubusercontent.com/brattex/hpc-ecosystems-openhpc101/master/Vagrantfile</a> (note, save file as <strong>Vagrantfile</strong> with no file extensions)</p>
</li>
</ol>
<h3 id="deploy-hpc-ecosystems-openhpc-smshost">Deploy HPC Ecosystems OpenHPC SMShost</h3>
<ol start="3">
<li>
<p>The following command (<strong>vagrant up</strong>) will initialise the vagrant environment (and download the vagrant VM) - the entire process may take (many) several minutes depending on the internet connection.</p>
</li>
<li>
<p><code>vagrant up</code></p>
<ol>
<li>This will read the Vagrantfile parameters and …</li>
<li>Create the Virtualbox (or other Hypervisor) framework (such as vCPUs, RAM, NIC’s, etc.) then …</li>
<li>Download the CentOS image and install it onto the VM.
<ol>
<li>Note: this is currently CentOS 7.5 <strong><span>64bit</span></strong></li>
</ol>
</li>
<li>Once the VM is booted up for the first time, a Vagrant shell script will run <s>a <strong>yum update</strong> and also</s> some <strong>yum install</strong> commands, all “behind-the-scenes”.</li>
</ol>
</li>
<li>
<p>Once the process is completed you should be able to SSH into the VM either through (a) or (b) below.<br>
5. <code>vagrant ssh</code><br>
6. whatever SSH client to 127.0.0.1:2229<br>
7. The username and password is</p>
<pre><code> **vagrant::vagrant**
</code></pre>
</li>
<li>
<p>Once you are inside your VM, the next step is to install the OpenHPC environment onto the VM…</p>
</li>
</ol>
<h2 id="install-and-prepare-openhpc-sms-host">Install and prepare OpenHPC SMS Host</h2>
<pre><code>HINT: There are TWO configuration files
o input.local - advanced customisation of the final system (FINAL SYSTEM)
o setenv.c - simple customisation for the DEMO system
to 'source' the input.local file (i.e. to load into OS environment memory) -
source input.local

to 'source' the setenv.c file (to load into environment memory) - 
source setenv.c

AFTER THE COMMAND THE ENVIRONMENT VARIABLES (YOUR SETTINGS THAT YOU DEFINED IN THE FILE) ARE UPDATED.

</code></pre>
<ol start="7">
<li>
<p>Download your chosen OpenHPC image guide from:</p>
<p><a href="https://openhpc.community/downloads/">https://openhpc.community/downloads/</a></p>
</li>
</ol>
<pre><code>CentOS 7 x86_64: Install guide with xCAT (Stateless) + SLURM (PDF)

</code></pre>
<ol>
<li>
<p><em>It is a useful approach to store this PDF in the **/vagrant **shared directory</em><br>
2. The shared directory <em>on the VM</em> is located at <strong>/vagrant.</strong><br>
3. The shared directory <em>on your host machine</em> is located in the head/root of the directory structure that hosts the VM, and will be the same path as the location for the <strong>Vagrantfile</strong> you downloaded earlier <em>(e.g. /openhpc/smshost/)</em></p>
<pre><code>     ```
     HINT: /vagrant is not the same as /home/vagrant!!

     ```
</code></pre>
</li>
</ol>
<p><img src="images/2019-06-27_localhost.png?raw=true" alt="vagrant shared folder on host"></p>
<p><img src="images/2019-06-27_openHPC.png" alt="vagrant shared folder on VM"></p>
<ol>
<li>
<p>Either <em>directly on the VM</em> or <em>through the Vagrant shared directory</em>, edit the base image template <strong><s>input.local</s> setenv.c</strong> \</p>
<ol>
<li>The base image template is named **input.local **and is downloaded from OpenHPC Docs or from the git repository below (it is recommended to download the git repository version because this has been modified slightly for HPC Ecosystems sites). <strong>The simplified version is setenv.c.</strong></li>
<li>HINT: for simplicity, we recommend to use setenv.c for the workshop because it has a simplified list of parameters</li>
</ol>
</li>
</ol>
<ul>
<li>download  <strong><s>input.local</s> setenv.c</strong> from the link below and save it in** <em>/vagrant</em>** (which is accessible in the VM): <a href="https://github.com/brattex/hpc-ecosystems-openhpc101">https://github.com/brattex/hpc-ecosystems-openhpc101</a><br>
9. Change appropriate parameters after the “-” symbol in the configuration file<br>
4. You do not need to be concerned about uncommenting what is not needed for your particular environment; this base image template is used by <strong><a href="http://recipe.sh">recipe.sh</a></strong> for automated installations and will check all the parameters before installing anything.<br>
5. In our case, we are doing the steps run in <strong><a href="http://recipe.sh">recipe.sh</a></strong> manually, and only the relevant global parameters for your chosen configuration will be used.<br>
6. HINT: You do not need to change any settings for the training workshop - but it is a good idea to change the <strong>sms_name</strong>.<br>
1. Once updated, within the VM run<br>
2. <code>. ./setenv.c</code><br>
3. and verify your new sms_name setting by<br>
4. <code>echo $sms_name</code><br>
5. This should display the name you set in <strong>setenv.c</strong><br>
10. <strong>NOTE: You must carefully plan your system design before making changes to this file - a few <span>minutes</span> of planning will save you <span>days</span> of debugging!</strong><br>
11. SOURCE your configuration file (setenv.c or input.local) when you are ready to load the parameters into your current shell session…</li>
</ul>
<ol start="8">
<li>Follow the OpenHPC guide that you have selected from <a href="https://openhpc.community/downloads/">https://openhpc.community/downloads/</a> (above)</li>
</ol>
<h2 id="install-and-prepare-openhpc-hpc-vclients-host">Install and prepare OpenHPC HPC vClients Host</h2>
<ol start="9">
<li>Included in github are two virtual clients to test with the SMS host (under openhpc client vms/)<br>
12. OpenHPC Client 00<br>
7. Virtual MAC address 080027F9F3B1 (internal network ‘hpcnet’)<br>
13. OpenHPC Client 01<br>
8. Virtual MAC address 080027F59A31 (internal network ‘hpcnet’)</li>
<li>Both clients are Virtualbox VMs ready to accept a 64bit RHEL-type OS with 1GB RAM and 8GB dynamic disk. Default to PXE boot.<br>
14. NOTE: As of v1.3.7 the clients must have <strong>2GB of RAM</strong> - you can edit this within Virtualbox via <strong>Settings → System → Base Memory</strong></li>
</ol>
<h2 id="openhpc-example-walkthrough">OpenHPC Example walkthrough</h2>
<p>An example walkthrough is available in this Google Doc:</p>
<p><a href="https://docs.google.com/document/d/e/2PACX-1vQ3YNvqfsWkAdW-LKKaWOR4Jw-PwqEWdCojg5O_WNoReYlytS0MLaTVZqVudJg0LS3Ky2z15yG6Pjpl/pub">https://docs.google.com/document/d/e/2PACX-1vQ3YNvqfsWkAdW-LKKaWOR4Jw-PwqEWdCojg5O_WNoReYlytS0MLaTVZqVudJg0LS3Ky2z15yG6Pjpl/pub</a></p>
<h2 id="basic-overview-of-hpc-design-choice">Basic Overview of HPC Design Choice</h2>
<ul>
<li><a href="https://docs.google.com/drawings/d/1dLHmKsdG1V1BkKHcwAN7WEJpGx49unMi7xDwe-L4FnQ/edit?usp=sharing">A basic overview of the planned layout of the OpenHPC “SMS” in relation to the WWW/WAN and HPC/LAN</a>
<ul>
<li>this will be useful in determining which ethX interface to use where!</li>
</ul>
</li>
</ul>
<h2 id="known-issues--bugs">Known Issues / Bugs</h2>
<ul>
<li>vagrant image eth1 becomes set to “host only adapter” but should be “internal” and “hpcnet” for the DHCP to issue out on HPC network (which clients are expecting to receive DORA on).</li>
<li>no local user defined in WW guide - add a local user before booting nodes</li>
<li><a href="https://groups.io/g/OpenHPC-users/topic/22676845?p=,,,20,0,0,0::recentpostdate%2Fsticky,,,20,0,0,22676845">https://groups.io/g/OpenHPC-users/topic/22676845?p=,20,0,0,0::recentpostdate%2Fsticky,20,0,0,22676845</a>
<ul>
<li>when the VM is “reset” instead of cold reboot (power off and on) it gets stuck in a stale state</li>
<li>a workaround might be to boot from the ipxe ISO (see final post in link above)</li>
</ul>
</li>
<li>VM clients have 1GB of RAM which is usable but causes some issues with the RAMdisk - increasing to 4GB is good but not necessarily practical - try 2GB and see if this improves performance.</li>
</ul>
<h2 id="other-references">Other References</h2>
<ul>
<li>CHPC OpenHPC presentation slides
<ul>
<li><a href="https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing">https://docs.google.com/presentation/d/1sXXEJKCml8pRlv1M1M5lHaewRON_-9LZdqFXbYmI9MY/edit?usp=sharing</a></li>
</ul>
</li>
</ul>
<!-- Docs to Markdown version 1.0&#946;17 -->

