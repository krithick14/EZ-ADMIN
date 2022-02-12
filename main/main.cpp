#include <iostream>
#include <fstream>
#include "server.cpp"
#include "backup.cpp"'
#include "schedule.cpp"
using namespace std;
int main()
{
    system("clear");
    while (1)
    {
        int option;

        cout << exec("figlet -c Admin Menu");
        cout << "\n";
        system("sudo echo admin > /dev/null");
        cout << exec("systemctl status apache2 | grep -i Active") << "\n";
        cout << "\n";

        cout << "\tLocal Ip :" << exec("hostname -I | awk '{print $1}'");

        // LIST OF OPTIONS

        cout << "\n\n\t1)Start Server\n\n";
        cout << "\t2)Stop Server\n\n";
        cout << "\t3)Restart Server\n\n";
        cout << "\t4)Backup Files\n\n";
        cout << "\t5)Schedule Server\n\n";
        cout << "\t6)View Server Logs\n\n";
        cout << "\t7)Clear Server Logs\n\n";
        cout << "\t8)Know about commands\n\n";
        cout << "\t9)Exit\n\n\n";
        cout << "\tEnter Your Option: ";
        cin >> option;
        Server server;
        Util obj;
        switch (option)
        {
        case 1:
        {
            // STARTING THE SERVER
            server.start();
            server.menu();
            break;
        }

        case 2:
        {
            // STOPPING THE SERVER
            server.stop();
            server.menu();
            break;
        }
        case 3:
        {
            // RESTARTING THE SERVER
            server.restart();
            server.menu();
            break;
        }

        case 4:
        {
            // BACKING UP THE SERVER
            Backup obj;
            obj.bckup();
            server.menu();
            break;
        }
        case 5:
        {
            // SCHEDULING SERVER FUNCTIONS
            schedule obj;
            Server server;
            obj.schedule_menu();
            server.menu();
            break;
        }
        case 6:
        {
            obj.viewlogs();
            server.menu();
            break;
        }
        case 7:
        {
            // CLEARING LOGS

            obj.clearlogs();
            
            server.menu();
            break;
        }
        case 8:
        {
            // HELP MENU
            string cmd;
            cout << "\tEnter a command : ";
            cin >> cmd;
            obj.help(cmd);
            server.menu();
            break;
        }
        case 9:
        {
            // EXIT
            system("killall xterm  2> /dev/null");
            cout << "\tEXITTED\n";
            return 0;
            break;
        }

        default:
        {
            // DEFAULT OPTION FOR INVALID INPUT
            cout << "\tInvalid Option\n";
            server.menu();
            break;
        }
        }
    }
    return 0;
}
