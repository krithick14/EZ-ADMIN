#include <iostream>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <fstream>
using namespace std;  
int getch() {
    struct termios oldt, newt;int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

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
class Util
{
public:
    // VIEW LOGS
    void viewlogs(){
            ifstream file;
            file.open("logs.txt");
            string data;
            system("clear");
            cout << exec("figlet -c L O G S") << "\n\n\n\n";
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
                file.close();
            }
    }

    // CLEAR LOGS
    void clearlogs()
    {
        int attempt=0;
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        while(attempt != 2)
        {
            string temp="",pass="admin123";
            cout << "\n\tEnter Password: ";
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            cin >> temp;
            if(temp == pass)
            {    
                ofstream file;
                file.open("logs.txt");
                cout << "\n\n\tLogs Cleared Sucessfully\n";
                file.close();
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                break;
            }
            else
            {
                cout << "\n\n\tInvalid password !!!" << endl;
                // cout << temp << endl << pass;
                attempt++;
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                if(attempt == 2)
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
        string full_cmd = "man " + cmd;
        const char *full = full_cmd.c_str();
        system(full);
    }
};
