#include <iostream>
#include <sstream>
#include <arpa/inet.h>
#include "Schedule.cpp"

using namespace std;

class Search
{
public:
    // SEARCH MENU
    void search_menu()
    {
        int opt;
        system("figlet -c Search");
        cout << "\n\t1)Search by Date\n\n\t2)Search by Month\n";
        cout << "\n\tEnter your choice: ";
        cin >> opt;
        if (opt == 1)
        {
            string date;
            cout << "\n\tEnter date in 01/Jan/2022 format : ";
            cin >> date;
            search_with_date(date);
        }
        else if (opt == 2)
        {
            string month;
            cout << "\n\tEnter Month in given Format (Jan,Sep) : ";
            cin >> month;
            search_with_month(month);
        }
        else
        {
            cout << "\n\tInvalid Choice\n";
            return;
        }
    }

    // FUNCTION TO VALIDATE IP ADDRESSES

    bool is_ip_address(const string &str)
    {
        struct sockaddr_in sa;
        return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr)) != 0;
    }

    // FUNCTION TO VALIDATE DATE

    bool is_date(string date)
    {
        bool valid = false;
        string *s = splitDate(date);
        const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        if ((stoi(s[0]) > 0 && stoi(s[0]) <= 31))
        {
            for (int i = 0; i < 12; i++)
            {
                if (s[1] == months[i])

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

            n = exec(command + " | wc -l");
            if (stoi(n) == 0)
            {
                cout << "\n\tNo connections found with " << ip << "  !!!\n";
            }
            else
            {
                cout << "\n\t" << ip << " has connected with the server\n\tNumber of connections = " << n << "\n\n\tDetails of connections \n";
                system("printf \"\\tS.no\\tIP\\t\\tTime Stamp\\n\" ");
                system(command.c_str());
            }
        }
        else
        {
            cout << "\n\tInvalid IP Address\n";
        }
    }

    // DETAILS OF CONNECTIONS ON GIVEN DATE
    void search_with_date(string date)
    {

        if (is_date(date))
        {
            string num = "0";

            string command = "cat /var/log/apache2/access.log | grep " + date + " | awk \'{print \"\\t\" NR \"\\t\"$1 \"\\t\" $4 \" \" $5 }\' ";
            num = exec(command + " | wc -l");
            if (stoi(num) == 0)
            {
                cout << "\n\tNo Logs found on date " << date << " !!!\n";
            }
            else
            {
                system("printf \"\\tS.no\\tIP\\t\\tTime Stamp\\n\" ");
                system(command.c_str());
            }
        }
        else
        {
            cout << "\n\n\tInvalid Date\n";
        }
    }

    // DETAILS OF CONNECTION IN GIVEN MONTH

    void search_with_month(string month)
    {

        // CHECKING VALID MONTH
        
        bool valid_month = false;
        const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 12; i++)
        {
            if (month == months[i])
            {
                valid_month = true;
            }
        }


        if (valid_month)
        {
            string num = "0";

            string command = "cat /var/log/apache2/access.log | grep " + month + " | awk \'{print \"\\t\" NR \"\\t\"$1 \"\\t\" $4 \" \" $5 }\' ";
            num = exec(command + " | wc -l");
            if (stoi(num) == 0)
            {
                cout << "\n\tNo Logs found in " << month << " !!!\n";
            }
            else
            {
                system("printf \"\\tS.no\\tIP\\t\\tTime Stamp\\n\" ");
                system(command.c_str());
            }
        }
        else
        {
            cout << "\n\tInvalid Month\n";
            return;
        }
    }
};