#include <iostream>
#include <fstream>
#include "server.cpp"
#include "backup.cpp"
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
        cout << exec("systemctl status apache2 | grep -i Active ") << "\n";
        cout << "\n";

        cout << "\tLocal Ip :" << exec("hostname -I | awk '{print $1}'");

        cout << "\n\n\t1)Start Server\n\n";
        cout << "\t2)Stop Server\n\n";
        cout << "\t3)Restart Server\n\n";
        cout << "\t4)Backup Files\n\n";
        cout << "\t5)Schedule Server\n\n";
        cout << "\t6)View Logs\n\n";
        cout << "\t7)Clear Logs\n\n";
        cout << "\t8)Know about commands\n\n";
        cout << "\t9)Exit\n\n\n";
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
            schedule obj;
            Server server;
            obj.schedule_menu();
            server.menu();
            break;
        }
        case 6:
        {
            ifstream file;
            file.open("logs.txt");
            string data;
            system("clear");
            cout << exec("figlet -c L O G S")<<"\n\n\n\n";
            file.seekg(0, ios::end);
            int file_size = file.tellg();
            if (file_size == 0)
            {
                cout << "\n\n\tNo logs Found";
            }
            else
            {
                file.seekg(0, ios::beg);
                while (getline(file, data))
                    cout << "\t" << data << endl;
                file.close();
            }
            server.menu();
            break;
        }
        case 7:
        {
            ofstream file;
            file.open("logs.txt");
            cout << "\tLogs Cleared Sucessfully\n";
            file.close();
            break;
        }
        case 8:
        {
            string cmd;
            Util obj;
            cout << "\tEnter a command : ";
            cin >> cmd;
            obj.help(cmd);
            server.menu();
            break;
        }
        case 9:
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
