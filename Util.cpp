#include <iostream>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <fstream>
// Hi
using namespace std;

// FUNCTION TO EXECUTE SYSTEM COMMANDS AND RETURN THE OUTPUT OF THE COMMAND

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

// FUNCTION TO SPLIT DATE USING '/'
string *splitDate(string str)
{
    string *arr = new string[25];
    int i = 0;
    string delimiter = "/";
    size_t pos = 0;
    string token;
    str += "/";
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        arr[i] = token;

        str.erase(0, pos + delimiter.length());
        i++;
    }
    return arr;
}

class Util
{
public:
    // VIEW SERVER LOGS
    void viewlogs()
    {
        ifstream file;
        file.open(".server_logs.txt");
        string data;
        system("clear");
        cout << exec("figlet -c -w 100 S E R V E R - L O G S") << "\n\n\n\n";
        file.seekg(0, ios::end);
        int file_size = file.tellg();
        if (file_size == 0)
        {
            cout << "\n\n\tNo logs Found";
        }
        else
        {
            file.seekg(0, ios::beg);
            while (getline(file, data))
                cout << "\t" << data << endl;
        }
        file.close();
    }

    // CLEAR SERVER LOGS
    void clearlogs()
    {
        int attempt = 0;

        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;

        while (attempt != 2)
        {
            string temp = "", pass = "admin123";
            cout << "\n\tEnter Password: ";
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            cin >> temp;
            if (temp == pass)
            {
                ofstream file;
                file.open(".server_logs.txt");
                cout << "\n\n\tLogs Cleared Sucessfully\n";
                file.close();
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                break;
            }
            else
            {
                cout << "\n\n\tInvalid password !!!" << endl;
                attempt++;
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                if (attempt == 2)
                {
                    cout << "\n\n\tMAX ATTEMPTS REACHED\n";
                    exit(1);
                }
            }
        }
    }

    // HELP MENU
    void help(string cmd)
    {
        string full_cmd = cmd + " --version 1> /dev/null 2> /dev/null";
        int exit_code = system(full_cmd.c_str());
        if (exit_code != 0)
        {
            cout << "\n\t" << cmd << " - Command not found\n";
            return;
        }
        string command = "man " + cmd;
        system(command.c_str());
    }
};
