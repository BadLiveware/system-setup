#!/usr/bin/env bash

ip_address=$(powershell.exe -noprofile -command 'Get-NetAdapter -Physical -name "Ethernet*" | select-object -ExpandProperty ifIndex | unique | % { Get-NetIPAddress -AddressFamily IPv4 -InterfaceIndex $_ } | select-object -expandproperty ipaddress | % { "$_ windows.host" }' | select-object -first 1
host_name="windows.local"

# find existing instances in the host file and save the line numbers
matches_in_hosts="$(grep -n $host_name /etc/hosts | cut -f1 -d:)"
host_entry="${ip_address} ${host_name}"

echo "Please enter your password if requested."

if [ ! -z "$matches_in_hosts" ]
then
    echo "Updating existing hosts entry."
    # iterate over the line numbers on which matches were found
    while read -r line_number; do
        # replace the text of each line with the desired host entry
        sudo sed -i '' "${line_number}s/.*/${host_entry} /" /etc/hosts
    done <<< "$matches_in_hosts"
else
    echo "Adding new hosts entry."
    echo "$host_entry" | sudo tee -a /etc/hosts > /dev/null
fi