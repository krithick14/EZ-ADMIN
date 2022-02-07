#include<iostream>
#include<fstream>
#include "backup.cpp"
#include "command.cpp"
#include "schedule.cpp"

using namespace std;


string exec(string command) {
   char buffer[128];
   string result = "";
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   while (!feof(pipe)) {
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}

int main()
{
    system("clear");
    while(1){
    int option;

    system("figlet A d m i n  M e n u");
    cout << "\n";
    cout << "\t"<<exec("systemctl status apache2 | grep -i Active ") << "\n";
    cout << "\n";

    cout << "\tLocal Ip :" << exec("hostname -I | awk '{print $1}'");
    
    cout << "\n\n\t1)Start Server\n\n";
    cout << "\t2)Stop Server\n\n";
    cout << "\t3)Restart Server\n\n";
    cout << "\t4)Backup Files\n\n";
    cout << "\t5)Schedule Server\n\n";
    cout << "\t6)View Logs\n\n";
    cout << "\t7)Know about commands\n\n";
    cout << "\t8)Exit\n\n\n";
    cout << "\tEnter Your Option: ";
    cin >> option;
    Server server;

    switch (option)
    {
    case 1:
    {
        server.start();

        server.menu();
        break;
    }

    case 2:
    {
        server.stop();
        server.menu();
        break;
    }
    case 3:
    {
        server.restart();
        server.menu();
        break;
    }

    case 4:
    {
        Backup obj;
        obj.bckup();
        server.menu();
        break;
    }
    case 5:
    {
        schedule obj;
        Server server;
        obj.schedule_menu();
        server.menu();
        break;
    }
    case 6:
    {
        ifstream file;
        file.open("logs.txt");
        string data;
        system("clear");
        system("figlet L O G S");
        while(getline(file,data))
            cout << "\t" << data << endl;
        server.menu();
        break;
    }
    case 7:
    {
        string cmd;
        command obj2;
        cout << "\tEnter a command : ";
        cin >> cmd;
        obj2.cm(cmd);
        server.menu();
        break;
    }

    case 8:
    {
        cout << "\tEXITTED\n";
        return 0;
        break;
    }

    default:
    {
        cout << "\tInvalid Option\n";
        server.menu();
        break;
    }
}
    }
    return 0;
}
