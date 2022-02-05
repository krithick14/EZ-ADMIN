#include<iostream>
#include<fstream>
#include<unistd.h>
#include "backup.cpp"
#include "command.cpp"

using namespace std;
int main()
{
    while(1){
    int option;
    system("clear");

    system("figlet A d m i n  M e n u");
    cout << "\n";
    system("systemctl status apache2 | grep -i Active ");

    cout << "\n\n\t1)Start Server\n\n";
    cout << "\t2)Stop Server\n\n";
    cout << "\t3)Restart Server\n\n";
    cout << "\t4)Backup Files\n\n";
    cout << "\t5)Know about commands\n\n";
    cout << "\t6)Exit\n\n\n";
    cout << "\tEnter Your Option: ";
    cin >> option;
    Server server;

    switch (option)
    {
    case 1:
    {
        server.start();

        server.menu();
        break;
    }

    case 2:
    {
        server.stop();
        server.menu();
        break;
    }
    case 3:
    {
        server.restart();
        server.menu();
        break;
    }

    case 4:
    {
        Backup obj;
        obj.bckup();
        server.menu();
        break;
    }
    case 5:
    {
        string cmd;
        command obj2;
        cout << "\tEnter a command : ";
        cin >> cmd;
        obj2.cm(cmd);
        server.menu();
        break;
    }

    case 6:
    {
        cout << "\tEXITTED\n";
        return 0;
        break;
    }

    default:
    {
        cout << "\tInvalid Option\n";
        server.menu();
        break;
    }
}
    }
    return 0;
}
