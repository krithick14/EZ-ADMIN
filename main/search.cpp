#include <iostream>
#include <sstream>
#include "Util.cpp"
#include <arpa/inet.h>
using namespace std;

class search
{
public:
    // FUNCTION TO VALIDATE IP ADDRESSES
    bool is_ip_address(const string &str)
    {
        struct sockaddr_in sa;
        return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr)) != 0;
    }
    
    // DETAILS OF CONNECTION WITH GIVEN IP
    void search_with_ip(string ip)
    {
        string command = "cat /var/log/apache2/access.log | grep " + ip + " | awk \'{print \"\\t\" NR \"\\t\"$1 \"\\t\" $4 \" \" $5 }\' ";

        const char *exe_command = command.c_str();

        if (is_ip_address(ip))
        {
            string n = "0";

            n = exec(command + " | wc -l");
            int num = stoi(n);
            if (num == 0)
            {
                cout << "\n\tNo connections found with " << ip << "!!!\n";
            }
            else
            {
                cout << "\n\t" << ip << " has connected with the server\n\tNumber of connections = " << num << "\n\n\tDetails of connections \n";
                system("printf \"\\tS.no\\tIP\\t\\tTime Stamp\\n\" ");
                system(exe_command);
            }
        }
        else
        {
            cout << "\n\tInvalid IP Address\n";
        }
    }
};