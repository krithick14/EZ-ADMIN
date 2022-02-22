#!/bin/bash

function install {

    sudo apt install figlet apache2 at xterm tar
    sudo cp ./ez_admin.html /var/www/html/ez_admin.html
    g++ main.cpp -o ez-admin
    if [ $? -ne 0 ]; then
        echo "INSTALLATION FAILED !!!"
    fi
    ./ez-admin

}

echo -e "\n\n"
echo -e "\t\t\t===================\n"
echo -e "\t\t\t   SERVER MANAGER"
echo -e "\n\t\t\t==================="

echo -e "\n\t\t\tINSTALLING DEPENDENCIES\n\n\n"

ping -c 5 8.8.8.8 &>/dev/null

if [ $? -eq 0 ]; then
    install
else
    echo -e "\t\tNO INTERNET CONNECTION !!!"
    echo -e "\t\tINSTALLATION FAILED !!!"
fi
