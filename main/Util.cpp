#include <iostream>
#include <string>
using namespace std;

class Util
{
public:
    void help(string cmd)
    {
        string full_cmd = "man " + cmd;
        const char *full = full_cmd.c_str();
        system(full);
    }
  
};
