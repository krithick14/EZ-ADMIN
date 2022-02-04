#include<iostream>
#include<fstream>
#include<unistd.h>
#include "backup.cpp"

using namespace std;
int main()
{
    while(1){
    int option;
    system("clear");

    system("figlet A d m i n  M e n u");
    cout << "\n";
    int user;
    user = getuid();
    if (user != 0)
    {
        cout << "\t\nROOT Privleges needed\n";
        return 0;
    }
    system("systemctl status apache2 | grep -i Active ");

    cout << "\n\n\t1)Start Server\n\n";
    cout << "\t2)Stop Server\n\n";
    cout << "\t3)Restart Server\n\n";
    cout << "\t4)Backup Files\n\n";
    cout << "\t5)Exit\n\n\n";
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