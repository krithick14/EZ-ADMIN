#include <iostream>
#include <fstream>
#include "Server.cpp"
#include "Backup.cpp"
#include "Schedule.cpp"
using namespace std;
int main()
{
    system("clear");
    while (1)
    {
        int option=0;

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
        cout << "\t8)Search Client logs using IP Address\n\n";
        cout << "\t9)Search Client logs using Time\n\n";
        cout << "\t10)Know about commands\n\n";
        cout << "\t11)Exit\n\n\n";
        cout << "\tEnter Your Option: ";
        cin >> option;

        Server server;
        Util util;
        Search search;
        Backup backup;
        Schedule schedule;

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
            backup.bckup();
            server.menu();
            break;
        }
        case 5:
        {
            // SCHEDULING SERVER FUNCTIONS

            schedule.schedule_menu();
            server.menu();
            break;
        }
        case 6:
        {
            util.viewlogs();
            server.menu();
            break;
        }
        case 7:
        {
            // CLEARING LOGS

            util.clearlogs();

            server.menu();
            break;
        }
        case 8:
        {
            // SEARCH LOGS USING IP ADDRESS

            string ip;
            cout << "\n\tEnter an IP Address: ";
            cin >> ip;
            search.search_with_ip(ip);
            server.menu();
            break;
        }
        case 9:
        {
            // SEARCH LOGS USING DATE/MONTH
            
            search.search_menu();
            server.menu();
            break;
        }
        case 10:
        {
            // HELP MENU
            string cmd;
            cout << "\n\tEnter a command : ";
            cin >> cmd;
            util.help(cmd);
            server.menu();
            break;
        }
        case 11:
        {
            // EXIT
            system("killall xterm  2> /dev/null");
            cout << "\tEXITED\n\n";
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
