#include <iostream>
#include <fstream>
using namespace std;
class schedule
{
public:
    // FUNCTION TO DISPLAY THE SCHEDULE MENU OPTIONS
    void schedule_menu()
    {
        cout << "\t================\n";
        cout << "\t SCHEDULE MENU\n";
        cout << "\t================\n";
        cout << "\t1)Schedule Start\n\n";
        cout << "\t2)Schedule Stop\n\n";
        cout << "\t3)Schedule Restart\n\n";
        cout << "\t4)Remove all Scheduled JOBS\n\n";
        cout << "\t5)Exit\n\n";
        int opti;
        cout << "\tEnter your choice: ";
        cin >> opti;
        string time;
        if (opti == 1)
        {
            cout << "\tEnter Start Time in 24 Hours Format (Eg: 10.00) :";
            cin >> time;
            // START
            schedule_start(time);
        }
        if (opti == 2)
        {
            cout << "\tEnter Stop Time in 24 Hours Format (Eg: 10.00) :";
            cin >> time;
            // STOP
            schedule_stop(time);
        }
        if (opti == 3)
        {
            cout << "\tEnter Restart Time in 24 Hours Format (Eg: 10.00) :";
            cin >> time;
            // RESTART
            schedule_restart(time);
        }
        if (opti == 4)
        {
            // REMOVE ALL SCHEDULED TASKS
            system("for i in `atq | awk '{print $1}'`;do atrm $i;done");
            cout << "\tAll Scheduled tasks removed\n";
        }
        if (opti == 5)
        {
            exit(0);
        }
    }

    // SCHEDULING START
    void schedule_start(string time)
    {
        // int time_cpy=stoi(time);

        string start_command = "echo 'sudo service apache2 start' | sudo at " + time + " today 2> /dev/null";

        fstream out_file;
        out_file.open("server_logs.txt", ios::app);
        out_file << "Server Start Scheduled by " << getenv("USER") << " at " << time << "\n";

        cout << "\tServer Start Scheduled by " << getenv("USER") << " at " << time << "\n";
        const char *command = start_command.c_str();
        system(command);
        out_file.close();
    }

    // SCHEDULING STOP
    void schedule_stop(string time)
    {
        string start_command = "echo 'sudo service apache2 stop' | sudo at " + time + " today 2> /dev/null";

        fstream out_file;
        out_file.open("server_logs.txt", ios::app);
        out_file << "Server Stop Scheduled by " << getenv("USER") << " at " << time << "\n";

        cout << "\tServer Stop Scheduled by " << getenv("USER") << " at " << time << "\n";
        const char *command = start_command.c_str();
        system(command);
        out_file.close();
    }

    // SCHEDULING RESTART
    void schedule_restart(string time)
    {
        string start_command = "echo 'sudo service apache2 restart' | sudo at " + time + " today 2> /dev/null";

        fstream out_file;
        out_file.open("server_logs.txt", ios::app);
        out_file << "Server Restart Scheduled by " << getenv("USER") << " at " << time << "\n";

        cout << "\tServer Restart Scheduled by " << getenv("USER") << " at " << time << "\n";
        const char *command = start_command.c_str();
        system(command);
        out_file.close();
    }
};
