#include <iostream>
#include <string>


using namespace std;

int main()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    getline(cin, s);

    cout << s << endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}