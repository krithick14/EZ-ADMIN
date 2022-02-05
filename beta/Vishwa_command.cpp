#include<iostream>
#include<string>

using namespace std;

class command
{
    public:

    void cm(string cmd)
    {
        string full_cmd = "man "+cmd;
        const char* full = full_cmd.c_str();
        system(full);
    }
};
