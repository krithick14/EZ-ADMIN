#include<iostream>
using namespace std;
class Server
{
    public:
        int stat;
        Server()
        {
            stat = system("systemctl status apache2 | grep -i dead >> /dev/null");
        }
        bool status()
        {    
            
            if(stat == 0)
                return true;
            else
                return false;
        }

        void start()
        {
            if(status())
            {
                system("sudo service apache2 start");
                cout << "\tServer Started\n";
            }else
            {   
                cout << "\tServer Already Running\n";
            }
        }
        void stop()
        {
            if(!status())
            {
                system("sudo service apache2 stop");
                cout << "\tServer Stopped\n";
            }else
            {   
                cout << "\tServer Not Running\n";
            }
        }

        void restart()
        {
            system("sudo service apache2 restart");
            cout << "\tServer Restarted Sucessfully\n";
        }
};