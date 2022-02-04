#include<iostream>
#include "server.cpp"
using namespace std;
int main()
{
    int option;
    system("clear");
    // cout << "\t===================\n";
    // cout << "\t     ADMIN MENU    \n";
    // cout << "\t===================\n";


    system("figlet A d m i n  M e n u");
    cout << "\n";
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
        server.start();
        break;
    
    case 2:
        server.stop();
        break;
    
    case 3:
        server.restart();
        break;
    
    case 4:
        cout << "\tServer Backup\n";
        break;
    
    case 5:
        cout << "\tEXITTED\n";
        return 0;
        break;
    
    default:
        cout << "\tInvalid Option\n";
        break;
    }
    return 0;
}