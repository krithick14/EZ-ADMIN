#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class Server
{
public:
    int stat;
    Server()
    {
        // GETTING THE STATUS OF THE SERVER
        stat = system("pgrep apache2 >> /dev/null");
    }

    // FUNCTION TO RETURN TO MENU
    void menu()
    {
        char opt;
        cout << "\n\tDo you want to return to the menu (Y/N): ";
        cin >> opt;
        if (!(opt == 'y' || opt == 'Y'))
            exit(0);
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
            time_t ttime = time(0);
            char *time = ctime(&ttime);
            cout << "\n\tServer Started by " << getenv("USER") << " on " << time << "\n\n";
            fstream out_file;
            out_file.open("logs.txt", ios::app);
            out_file << "Server Started by " << getenv("USER") << " on " << time << "\n";
            cout << "\n\tClick the link to View: "
                 << "http://localhost/\n\n";
            out_file.close();
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
            system("sudo service apache2 stop");
            time_t ttime = time(0);
            char *time = ctime(&ttime);
            cout << "\n\tServer Stopped by " << getenv("USER") << " on " << time << "\n";
            fstream out_file;
            out_file.open("logs.txt", ios::app);
            out_file << "Server Stopped by " << getenv("USER") << " on " << time << "\n";
            cout << "\tServer Stopped\n";
            out_file.close();
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
        system("sudo service apache2 restart");
        time_t ttime = time(0);
        char *time = ctime(&ttime);
        cout << "\n\tServer Restarted by " << getenv("USER") << " on " << time << "\n\n";
        fstream out_file;
        out_file.open("logs.txt", ios::app);
        out_file << "Server Restarted by " << getenv("USER") << " on " << time << "\n";
        cout << "\tServer Restarted Sucessfully\n";
        cout << "\tClick the link to View: "
             << "http://localhost/\n\n";
        out_file.close();
    }
};