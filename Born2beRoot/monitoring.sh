#!/bin/bash


# Display system information
(
echo "   #Architecture: $(uname -a)"
echo "   #CPU physical : $(grep 'physical id' /proc/cpuinfo | sort -u | wc -l)"
echo "   #vCPU : $(grep 'processor' /proc/cpuinfo | sort -u | wc -l)"
echo "   #Memory Usage: $(free -m | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}')"

disk_total=$(df -hl -BM | grep '^/dev' | awk '{sum+=$2} END{print sum}')
disk_used=$(df -hl -BM | grep '^/dev' | awk '{sum+=$3} END{print sum}')
disk_usage=$(awk -v used="$disk_used" -v total="$disk_total" 'BEGIN {printf "%d\n", (100*used/total)}')
disk_total_gb=$(awk -v total="$disk_total" 'BEGIN {printf "%d", total/1024}')
echo "   #Disk Usage: $disk_used/$disk_total_gb""Gb ($disk_usage%)"
echo "   #CPU load: $(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\) id.*/\1/" | awk '{print 100 - $1"%"}')"
echo "   #Last boot: $(who -b | awk '{print $3,$4}')"
echo "   #LVM use: $(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)"
echo "   #Connections TCP: $(ss -ta | grep ESTAB | wc -l) ESTABLISHED"
echo "   #User log: $(who | wc -l)"
echo "   #Network: IP $(hostname -I) ($(ip link | grep "link/ether" | awk '{print $2}'))"
echo "   #Sudo: $(journalctl _COMM=sudo | grep COMMAND | wc -l) cmd"
) | wall

exit 0