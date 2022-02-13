#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
fstream out_file;

class Server
{
    time_t ttime;
    char *now;

public:
    int stat;

    Server()
    {
        ttime = time(0);
        now = ctime(&ttime);
        out_file.open("server_logs.txt", ios::app);

        // GETTING THE STATUS OF THE SERVER
        stat = system("pgrep apache2 >> /dev/null");
    }

    ~Server()
    {
        out_file.close();
    }
    // FUNCTION TO RETURN TO MENU
    void menu()
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

    // FUNCTION TO CHECK STATUS OF SERVER
    bool status()
    {
        if (stat == 0)
            return true;
        else
            return false;
    }

    // FUNCTION TO START THE SERVER
    void start()
    {
        if (!status())
        {
            system("sudo service apache2 start");
            system("killall xterm  2> /dev/null");
            system("xterm -T Client_logs -fa 'Monospace' -fs 12 -e  watch \"cut -d \' \'  -f 1,4,5 /var/log/apache2/access.log | tr -s ' ' '\t'  \" & ");

            cout << "\n\tServer Started by " << getenv("USER") << " on " << now << "\n\n";
            out_file << "Server Started by " << getenv("USER") << " on " << now << "\n";
            cout << "\n\tClick the link to View: "
                 << "http://127.0.0.1/\n\n";
        }
        else
        {
            char opt;
            cout << "\tServer Already Running\n\tWould You Like to STOP (Y/N):";
            cin >> opt;
            if (opt == 'y' || opt == 'Y')
                stop();
        }
    }

    // FUNCTION TO STOP THE SERVER
    void stop()
    {
        if (status())
        {
            system("killall xterm  2> /dev/null");
            system("sudo service apache2 stop");
            cout << "\n\tServer Stopped by " << getenv("USER") << " on " << now << "\n";
            out_file << "Server Stopped by " << getenv("USER") << " on " << now << "\n";
            cout << "\tServer Stopped\n";
        }
        else
        {
            cout << "\tServer Not Running\n\tWould You Like to START (Y/N):";
            char opt;
            cin >> opt;
            if (opt == 'y' || opt == 'Y')
                start();
        }
    }

    // FUNCTION TO RESTART THE SERVER
    void restart()
    {
        system("killall xterm  2> /dev/null");
        system("sudo service apache2 restart");
        system("xterm -T Client_logs -fa 'Monospace' -fs 12 -e  watch \"cut -d \' \'  -f 1,4,5 /var/log/apache2/access.log | tr -s ' ' '\t'  \" & ");

        out_file << "Server Restarted by " << getenv("USER") << " on " << now << "\n";

        cout << "\n\tServer Restarted by " << getenv("USER") << " on " << now << "\n\n";
        cout << "\tServer Restarted Sucessfully\n";
        cout << "\tClick the link to View: "
             << "http://127.0.0.1/\n\n";
    }
};
