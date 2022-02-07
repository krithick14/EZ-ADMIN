#include<iostream>

using namespace std;
class schedule
{
    public:
        void schedule_menu()
        {
            cout << "\t================\n";
            cout << "\t SCHEDULE MENU\n";
            cout << "\t================\n";
            cout << "\t1)Schedule Start\n\n";
            cout << "\t2)Schedule Stop\n\n";
            cout << "\t3)Schedule Restart\n\n";
            cout << "\t4)Remove all Scheduled JOBS\n\n";
            cout << "\t5)Back\n\n";
            int opti;
            cout << "\tEnter your choice: ";
            cin >> opti;
            if(opti==1)
            {
                string time;
                cout << "\tEnter Start Time in 24 Hours Format (Eg: 10.00) :";
                cin >> time;
                schedule_start(time);
            }
            if(opti==2)
            {
                string time;
                cout << "\tEnter Stop Time in 24 Hours Format (Eg: 10.00) :";
                cin >> time;
                schedule_stop(time);
            }
            if(opti==3)
            {
                string time;
                cout << "\tEnter Restart Time in 24 Hours Format (Eg: 10.00) :";
                cin >> time;
                schedule_restart(time);
            }
            if(opti==4)
            {
                cout << "\tAll Scheduled tasks removed\n";
                system("for i in `atq | awk '{print $1}'`;do atrm $i;done");
            }
            if(opti==5)
            {
                return;
            }
        }
        void schedule_start(string time)
        {
            string start_command="echo 'sudo service apache2 start' | sudo at "+time+" today >> /dev/null";
            const char* command=start_command.c_str();
            system(command);
        }

        void schedule_stop(string time)
        {
            string start_command="echo 'sudo service apache2 stop' | sudo at "+time+" today >> /dev/null";
            const char* command=start_command.c_str();
            system(command);
        }

        void schedule_restart(string time)
        {
            string start_command="echo 'sudo service apache2 restart' | sudo at "+time+" today >> /dev/null";
            const char* command=start_command.c_str();
            system(command);
        }
};
