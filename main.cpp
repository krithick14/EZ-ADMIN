#include <iostream>
#include <fstream>
#include "Server.cpp"
using namespace std;

// FUNCTION TO CONFIRM EXIT
void confirm_exit()
{
    string opt;
    cout << "\n\tDo you want to return to the menu (Y/N): ";
    cin.ignore();
    getline(cin, opt);
    if (opt.length() == 0)
        return;
    if (!(opt == "Y" || opt == "y"))
    {
        system("killall xterm  2> /dev/null");
        cout << "\n\tEXITED\n";
        exit(0);
    }
}

//DISPLAY MENU
void menu()
{

    cout << "\n\n\t1)Start Server\n\n";
    cout << "\t2)Stop Server\n\n";
    cout << "\t3)Restart Server\n\n";
    cout << "\t4)Backup Files\n\n";
    cout << "\t5)Schedule Server\n\n";
    cout << "\t6)View Server Logs\n\n";
    cout << "\t7)Clear Server Logs\n\n";
    cout << "\t8)Search Client logs using IP Address\n\n";
    cout << "\t9)Search Client logs using Time Stamp\n\n";
    cout << "\t10)Know about commands\n\n";
    cout << "\t11)Exit\n\n\n";
    cout << "\tEnter Your Option: ";
}

// MAIN FUNCTION
int main()
{
    system("clear");
    while (1)
    {
        int option;

        system("figlet -c Admin Menu");
        cout << "\n";
        int exit_code=system("sudo echo admin > /dev/null");

        //Exits if Sudo password is wrong
        
        if(exit_code!=0)
        {
            exit(1);
        }
        cout << "\tStatus: " << exec("systemctl status apache2 | grep -i Active  |cut -d \" \" -f 1-6 --complement") << "\n";
        cout << "\n";

        cout << "\tLocal Ip :" << exec("hostname -I | awk '{print $1}'");
        menu();
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
            confirm_exit();
            break;
        }

        case 2:
        {
            // STOPPING THE SERVER
            server.stop();
            confirm_exit();
            break;
        }
        case 3:
        {
            // RESTARTING THE SERVER
            server.restart();
            confirm_exit();
            break;
        }

        case 4:
        {
            // BACKING UP THE SERVER
            backup.bckup();
            confirm_exit();
            break;
        }
        case 5:
        {
            // SCHEDULING SERVER FUNCTIONS

            schedule.schedule_menu();
            confirm_exit();
            break;
        }
        case 6:
        {
            // VIEW SERVER LOGS

            util.viewlogs();
            confirm_exit();
            break;
        }
        case 7:
        {
            // CLEARING SERVER LOGS

            util.clearlogs();
            confirm_exit();
            break;
        }
        case 8:
        {
            // SEARCH CLIENT LOGS USING IP ADDRESS

            string ip;
            cout << "\n\tEnter an IP Address: ";
            cin >> ip;
            search.search_with_ip(ip);
            confirm_exit();
            break;
        }
        case 9:
        {
            // SEARCH CLIENT LOGS USING DATE/MONTH

            search.search_menu();
            confirm_exit();
            break;
        }
        case 10:
        {
            // HELP MENU
            string cmd;
            cout << "\n\tEnter a command : ";
            cin >> cmd;
            util.help(cmd);
            confirm_exit();
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
            cout << "\n\tInvalid Option\n\n";
            exit(1);
            break;
        }
        }
    }
    return 0;
}
