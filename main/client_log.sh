#!/bin/bash
while [ 1 ]
do
    clear
    awk '{print $1 "\t" $4 "]" }' /var/log/apache2/access.log;
    sleep 2;
done
