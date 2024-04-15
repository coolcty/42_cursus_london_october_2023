#!/bin/bash

# Function to display information with a label
function display_info() {
  local label="$1"
  local value="$2"
  echo "# $label: $value"
}

# Get system information
architecture=$(uname -a)
physical_cpus=$(grep -c 'physical id'  /proc/cpuinfo)
virtual_cpus=$(grep cpu\\ MHz /proc/cpuinfo | wc -l)
mem_total=$(free -m | grep Mem: | awk '{print $2}')
mem_used=$(free -m | grep Mem: | awk '{print $3}')
mem_usage=$(echo "scale=2; 100 * $mem_used / $mem_total" | bc)
disk_total=$(df -h / | grep '^/dev' | awk '{print $2}')
disk_used=$(df -h / | grep '^/dev' | awk '{print $3}')
disk_usage=$(df -h / | grep '^/dev' | awk '{print $5}')
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_load=$(printf "%.1f" $cpu_op)
last_reboot=$(uptime -s)
lvm_active=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# Get network information
ip_address=$(hostname -I)
mac_address=$(ip link | grep "link/ether" | awk '{print $2}')

# Get user and sudo information
num_users=$(who | wc -l)
num_connections=$(ss -ta | grep ESTAB | wc -l)
sudo_count=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

display_info "Architecture" "$architecture"
display_info "CPU physical" "$physical_cpus"
display_info "vCPU" "$virtual_cpus"
display_info "Memory Usage" "$mem_used/$mem_total MB ($mem_usage%)"
display_info "Disk Usage" "$disk_used/$disk_total GB ($disk_usage%)"
display_info "CPU load" "$cpu_load"
display_info "Last boot" "$last_reboot"
display_info "LVM use"  "$lvm_active"
display_info "Connections TCP" "$num_connections"
display_info "User log" "$num_users"
display_info "Network" "$ip_address ($mac_address)"
display_info "Sudo" "$sudo_count cmd"

exit 0