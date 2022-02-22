#include <iostream>
#include <fstream>
#include "Search.cpp"
using namespace std;

class Backup
{
    fstream out_file;
    time_t ttime;
    char *now;

public:
    Backup()
    {
        // Get Time
        ttime = time(0);
        now = ctime(&ttime);

        // File Open
        out_file.open(".server_logs.txt", ios::app);

    }
    // FUNCTION TO BACKUP THE SERVER FILESs
    void bckup()
    {
        try
        {
        system("mkdir -p /home/$USER/backup_server");
        int exit_code=system("cd /var/www/html 2> /dev/null &&  sudo tar -cpf /home/$USER/backup_server/backup_$(date +%F).tar.gz ./* 2> /dev/null && sudo chown $USER /home/$USER/backup_server/backup_$(date +%F).tar.gz 2> /dev/null");
        if(exit_code!=0)
            throw exit_code;
        }
        catch(int exit_code)
        {
            cout << "\n\tBackup Failed : Something Went Wrong !!!\n";
            out_file << "Backup Failed on "<< now<<"\n";
            return;
        }
        cout << "\n\tBackup Completed\n\n";
        cout << "\tBackup Saved at " << exec("printf $HOME") << "/backup_server/\n\n";
        out_file << "Backup done on " <<now << "\n";
        cout << "\tView Backup Folder Press (Y/N) :";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            system("nautilus /home/$USER/backup_server &");
        }
        else
        {
            return;
        }
    }
};