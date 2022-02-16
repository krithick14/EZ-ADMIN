#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Server
{
    fstream out_file;
    time_t ttime;
    char *now;

public:
    int stat;

    // CONSTRUCTOR
    Server()
    {
        // Get Time
        ttime = time(0);
        now = ctime(&ttime);

        // File Open
        out_file.open(".server_logs.txt", ios::app);

        // GETTING THE STATUS OF THE SERVER
        stat = system("pgrep apache2 >> /dev/null");
    }

    // DESTRUCTOR
    ~Server()
    {
        // File Close
        out_file.close();
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
            // TRY BLOCK TO CHECK IF SERVER IS OPERATING PROPERLY
            try
            {
                int exit_code = system("sudo service apache2 start 2> /dev/null");
                if (exit_code != 0)
                    throw "Server Start failed - ";
            }
            catch (const char *err)
            {

                cout << "\n\tERROR !!!" << endl;
                cout << "\n\t" << err << getenv("USER") << " - " << now << "\n\n";
                out_file << err << getenv("USER") << " - " << now << "\n";

                return;
            }
            system("killall xterm  2> /dev/null");
            system("xterm -T Client_logs -fa 'Monospace' -fs 12 -e  watch \"tail -n 15 /var/log/apache2/access.log | cut -d \' \'  -f 1,4,5  | tr -s ' ' '\t'  \" & ");

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
            // TRY BLOCK TO CHECK IF SERVER IS OPERATING PROPERLY
            try
            {
                int exit_code = system("sudo service apache2 stop 2> /dev/null");
                if (exit_code != 0)
                    throw "Server Stop failed - ";
            }
            catch (const char *err)
            {

                cout << "\n\tERROR !!!" << endl;
                cout << "\n\t" << err << getenv("USER") << " - " << now << "\n\n";
                out_file << err << getenv("USER") << " - " << now << "\n";

                return;
            }

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
        // TRY BLOCK TO CHECK IF SERVER IS OPERATING PROPERLY
        try
        {
            int exit_code = system("sudo service apache2 restart 2> /dev/null");
            if (exit_code != 0)
                throw "Server Restart failed - ";
        }
        catch (const char *err)
        {

            cout << "\n\tERROR !!!" << endl;
            cout << "\n\t" << err << getenv("USER") << " - " << now << "\n\n";
            out_file << err << getenv("USER") << " - " << now << "\n";

            return;
        }
        system("xterm -T Client_logs -fa 'Monospace' -fs 12 -e  watch \"tail /var/log/apache2/access.log | cut -d \' \'  -f 1,4,5  | tr -s ' ' '\t'  \" & ");

        out_file << "Server Restarted by " << getenv("USER") << " on " << now << "\n";

        cout << "\n\tServer Restarted by " << getenv("USER") << " on " << now << "\n\n";
        cout << "\tServer Restarted Sucessfully\n";
        cout << "\tClick the link to View: "
             << "http://127.0.0.1/\n\n";
    }
};
