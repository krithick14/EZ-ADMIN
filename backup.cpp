#include <iostream>
using namespace std;
string exec(string command)
{
    char buffer[128];
    string result = "";

    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        return "popen failed!";
    }

    while (!feof(pipe))
    {

        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}
class Backup
{
public:
    void bckup()
    {
        system("mkdir -p /home/$USER/backup_server");
        system("cd /var/www/html && sudo sudo tar -cpf /home/$USER/backup_server/backup.tar.gz ./* > /dev/null");
        cout << "\tBackup Done\n";
        cout <<"\tBackup Saved at "<< exec("printf $HOME") <<"/backup_server/\n";
        cout << "\tView Backup Folder Press (Y/N) :";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            system("nautilus /home/$USER/backup_server");
        }
        else
        {
            return;
        }
    }
};