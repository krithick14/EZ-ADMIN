#!/bin/bash

function install {

    sudo apt install figlet apache2 at xterm nautilus
    if [ $? -ne 0 ]; then
        echo "INSTALLATION FAILED !!!"
    fi

}

echo -e "\n\n"
figlet -c SERVER MANAGER

echo -e "\n\t\t\tINSTALLING DEPENDENCIES ... \n\n\n"

ping -c 5 8.8.8.8 &>/dev/null

if [ $? -eq 0 ]; then
    install
else
    echo -e "\t\tNO INTERNET CONNECTION !!!"
    echo -e "\t\tINSTALLATION FAILED !!!"
fi
