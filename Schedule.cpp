#include <iostream>
#include <fstream>
#include "Util.cpp"

using namespace std;
class Schedule
{
    string time;
    fstream out_file;

public:
    int opti;
    string date = "date +%d/%b/%+4Y";

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

            string check_empty = exec("sudo atq | wc -l");

            if (stoi(check_empty) != 0)
            {
                system("for i in `sudo atq | awk '{print $1}'`;do sudo atrm $i;done");

                cout << "\tAll Scheduled tasks removed\n";
                out_file << "\nAll previously scheduled tasks were removed by " << getenv("USER") << " on " << exec(date) << "\n";
            }
            else
            {
                cout << "\tNo jobs are scheduled!!!\n";
            }
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
        try
        {
            string start_command = "echo 'sudo service apache2 start' | sudo at " + time + " today 2> /dev/null";
            int exit_code = system(start_command.c_str());

            if (exit_code != 0)
                throw exit_code;

            out_file << "\nServer Start Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
            cout << "\tServer Start Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
        }
        catch (int code)
        {
            cout << "\n\tServer Schedule Failed: Invalid Time\n";
        }
    }

    // SCHEDULING STOP
    void schedule_stop(string time)
    {
        try
        {
            string stop_command = "echo 'sudo service apache2 stop' | sudo at " + time + " today 2> /dev/null";
            int exit_code = system(stop_command.c_str());

            if (exit_code != 0)
                throw exit_code;

            out_file << "\nServer Stop Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
            cout << "\tServer Stop Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
        }
        catch (int code)
        {
            cout << "\n\tServer Schedule Failed: Invalid Time\n";
        }
    }

    // SCHEDULING RESTART
    void schedule_restart(string time)
    {
        try
        {
            string restart_command = "echo 'sudo service apache2 restart' | sudo at " + time + " today 2> /dev/null";
            int exit_code = system(restart_command.c_str());

            if (exit_code != 0)
                throw exit_code;

            out_file << "\nServer Restart Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
            cout << "\tServer Restart Scheduled by " << getenv("USER") << " at " << time << " on " << exec(date) << "\n";
        }
        catch (int code)
        {
            cout << "\n\tServer Schedule Failed: Invalid Time\n";
        }
    }
};
