#include <iostream>
#include <fstream>
using namespace std;
class Schedule
{
    string time;
    fstream out_file;

public:
    int opti;

    // Constructor
    Schedule()
    {
        // File Open
        out_file.open(".server_logs.txt", ios::app);
    }

    // Destructor
    ~Schedule()
    {
        out_file.close();
    }


    // FUNCTION TO DISPLAY THE SCHEDULE MENU OPTIONS
    void schedule_menu()
    {

        system("figlet -c Schedule Menu");

        cout << "\n\n\n\t1)Schedule Start\n\n";
        cout << "\t2)Schedule Stop\n\n";
        cout << "\t3)Schedule Restart\n\n";
        cout << "\t4)Remove all Scheduled JOBS\n\n";
        cout << "\t5)Exit\n\n";

        cout << "\tEnter your choice: ";

        cin >> opti;

        if (opti == 1)
        {
            cout << "\tEnter Start Time in 24 Hours Format (HH.MM) :";
            cin >> time;

            // START
            schedule_start(time);
        }
        else if (opti == 2)
        {
            cout << "\tEnter Stop Time in 24 Hours Format (HH.MM) :";
            cin >> time;

            // STOP
            schedule_stop(time);
        }
        else if (opti == 3)
        {
            cout << "\tEnter Restart Time in 24 Hours Format (HH.MM) :";
            cin >> time;

            // RESTART
            schedule_restart(time);
        }
        else if (opti == 4)
        {
            // REMOVE ALL SCHEDULED TASKS
            system("for i in `atq | awk '{print $1}'`;do atrm $i;done");
            
            cout << "\tAll Scheduled tasks removed\n";
        }
        else if (opti == 5)
        {
            return;
        }
        else
        {
            cout << "\n\tInvalid Option\n";
            exit(0);
        }
    }


    // SCHEDULING START
    void schedule_start(string time)
    {
        string start_command = "echo 'sudo service apache2 start' | sudo at " + time + " today 2> /dev/null";

        out_file << "\nServer Start Scheduled by " << getenv("USER") << " at " << time << "\n";
        cout << "\tServer Start Scheduled by " << getenv("USER") << " at " << time << "\n";
        
        system(start_command.c_str());
    }

    // SCHEDULING STOP
    void schedule_stop(string time)
    {
        string stop_command = "echo 'sudo service apache2 stop' | sudo at " + time + " today 2> /dev/null";

        out_file << "\nServer Stop Scheduled by " << getenv("USER") << " at " << time << "\n\n";
        cout << "\tServer Stop Scheduled by " << getenv("USER") << " at " << time << "\n";

        system(stop_command.c_str());
    }

    // SCHEDULING RESTART
    void schedule_restart(string time)
    {
        string restart_command = "echo 'sudo service apache2 restart' | sudo at " + time + " today 2> /dev/null";

        out_file << "\nServer Restart Scheduled by " << getenv("USER") << " at " << time << "\n\n";
        cout << "\tServer Restart Scheduled by " << getenv("USER") << " at " << time << "\n";

        system(restart_command.c_str());
    }
};
