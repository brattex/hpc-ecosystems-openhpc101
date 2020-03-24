# sms host information
sms_name=sms-host 	# Hostname for SMS server
sms_ip=10.10.10.10 	# Internal IP address on SMS server
###################################################################
# network related information
domain_name=hpcnet 	# Local network domain name
sms_eth_internal=eth1 # Internal Ethernet interface on SMS
internal_netmask=255.255.255.0 # Subnet netmask for internal network
ntp_server=time.google.com
###################################################################
# BMC information
bmc_username=
bmc_password=
###################################################################
# virtual cluster details
num_computes=2
###################################################################
# compute node 00
c_ip[0]=10.10.10.100
c_bmc[0]=
c_mac[0]=08:00:27:f9:f3:b1
c_name[0]=compute00
###################################################################
# compute node 01
c_ip[1]=10.10.10.101
c_bmc[1]=
c_mac[1]=08:00:27:F5:9A:31
c_name[1]=compute01
###################################################################
# compute node 02 --> not used in the Virtual Lab but for illustration
c_ip[2]=10.10.10.102
c_bmc[2]=
c_mac[2]=00:26:6C:FD:80:08
c_name[2]=compute02
###################################################################
compute_regex=compute*
compute_prefix=compute
iso_path=/vagrant
synclist=""
###################################################################
# optional extras
nagios_web_password=nagiospw
