#include <iostream>
#include <sstream>
#include "Util.cpp"
#include <arpa/inet.h>
using namespace std;

class Search
{
public:
    // FUNCTION TO VALIDATE IP ADDRESSES
    bool is_ip_address(const string &str)
    {
        struct sockaddr_in sa;
        return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr)) != 0;
    }

    bool is_date(string date)
    {
        bool valid = false;
        string *s;
        s = splitString(date);
        const string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        if ((stoi(s[0]) > 0 || stoi(s[0]) < 31))
        {
            for (int i = 0; i < 12; i++)
            {
                if (s[1] == month[i])

                    if (s[2].length() == 4)
                        valid = true;
            }
        }
        return valid;
    }

    // DETAILS OF CONNECTION WITH GIVEN IP
    void search_with_ip(string ip)
    {

        if (is_ip_address(ip))
        {
            string n = "0";
            string command = "cat /var/log/apache2/access.log | grep " + ip + " | awk \'{print \"\\t\" NR \"\\t\"$1 \"\\t\" $4 \" \" $5 }\' ";

            const char *exe_command = command.c_str();
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
    void search_with_date(string date)
    {

        // cout << is_date(date);
        if(is_date(date))
        {
            string n = "0";

            string command = "cat /var/log/apache2/access.log | grep " + date + " | awk \'{print \"\\t\" NR \"\\t\"$1 \"\\t\" $4 \" \" $5 }\' ";
            const char *exe_command = command.c_str();
            n = exec(command + " | wc -l");
            int num = stoi(n);
            if (num == 0)
            {
                cout << "\n\tNo Logs found on date " << date << " !!!\n";
            }
            else
            {
                system("printf \"\\tS.no\\tIP\\t\\tTime Stamp\\n\" ");
                system(exe_command);
            }
        }
        else
        {
            cout << "\n\tInvalid Date";
        }
    }
};