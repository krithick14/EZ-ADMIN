#!/bin/bash
function install
{
    sudo apt update
    sudo apt install figlet xterm apache2 at ;
}
figlet -c "SERVER MANAGER"
echo -e "\n\t\tINSTALLING DEPENDENCIES";
install
fi


