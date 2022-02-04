#include<iostream>
#include<string>
#include<cstring>

using namespace std;
void bckup(string path)
{
    string cmd = "cp -r /var/www/html";
    cmd=cmd+path;
    const char* full_path = cmd.c_str();
    cout<<full_path; 
}
int main () 
{
    bckup("Hello");
    return 0;
}