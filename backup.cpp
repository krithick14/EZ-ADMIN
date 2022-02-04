#include<iostream>
#include "server.cpp"
using namespace std;
class Backup:public Server
{
    public:
        void bckup()
        {
            if(!status())
            {    
                cout << "\tServer is Running\n\tCannot Take Backup\n";
                return;
            }

            string path;
            cout << "\tEnter the Path to save the Backup: ";
            cin >> path;
            string cmd = "cp -r /var/www/html ";
            cmd=cmd+path;
            const char* full_cmd = cmd.c_str();
            system(full_cmd);
            cout << "\tBackup Done\n";
            cout << "\tBackup is Stored in "<<path<<endl;
            cout << "\tView Backup Folder Press (Y/N) :";
            char choice;
            cin >> choice;
            if(choice == 'y' || choice == 'Y')
            {
                string command="nautilus " + path + " >> /dev/null";
                const char* open=command.c_str();
                system(open);
            }else
            {
                return;
            }
        }
};