#include<iostream>
#include<fstream>
#include "backup.cpp"
#include "schedule.cpp"
using namespace std;
int option;
void main_menu()
{

    system("figlet A d m i n  M e n u");
    cout << "\n";
    system("systemctl status apache2 | grep -i Active ");

    cout << "\n\n\t1)Start Server\n\n";
    cout << "\t2)Stop Server\n\n";
    cout << "\t3)Restart Server\n\n";
    cout << "\t4)Backup Files\n\n";
    cout << "\t5)Schedule Server\n\n";
    cout << "\t6)Exit\n\n\n";
    cout << "\tEnter Your Option: ";
    cin >> option;
}
int main()
{
    system("clear");    
    
    main_menu();
    Server server;
    switch (option)
    {
    case 1:
    {
        server.start();
        server.menu();
        main();
        break;
    }
    
    case 2:
    {
        server.stop();
        server.menu();
        main();
        break;
    }
    case 3:
    {
        server.restart();
        server.menu();
        main();
        break;
    }
    
    case 4:
    {
        Backup obj;
        obj.bckup();
        server.menu();
        main();
        break;
    }
    case 5:
    {
        schedule obj;
        Server server;
        obj.schedule_menu();
        server.menu();
        main();
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
    return 0;
}
