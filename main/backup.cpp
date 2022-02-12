#include <iostream>
#include "search.cpp"
using namespace std;

class Backup
{
public:
    // FUNCTION TO BACKUP THE SERVER FILESs
    void bckup()
    {
        
        system("mkdir -p /home/$USER/backup_server");
        system("cd /var/www/html &&  sudo tar -cpf /home/$USER/backup_server/backup_$(date +%F).tar.gz ./* && sudo chown $USER /home/$USER/backup_server/backup_$(date +%F).tar.gz > /dev/null");

        cout << "\tBackup Done\n";

        cout << "\tBackup Saved at " << exec("printf $HOME") << "/backup_server/\n";

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
