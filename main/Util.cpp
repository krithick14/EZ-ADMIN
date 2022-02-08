#include <iostream>
#include <string>
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
