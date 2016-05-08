#include <iostream>
#include <queue>
using namespace std;

const string GET = "GET";
const string PUT = "PUT";
const string ENMTYQUE = "ENMTY QUEUE!";

class Message
{
    public:
        string inputMsg;
        int para;
        int pri;
};

int main()
{
    priority_queue<string> msg;
    string input;
    while (cin >> input) 
    {
        if (input == GET)
        {
            if (msg.empty())
            {
                cout << ENMTYQUE << endl;
            }
            else
            {
                msg.top();
                msg.pop();
            }
        }
        else
        {
            Message mes;
            cin >> mes.inputMsg >> mes.para >> mes.pri;

        }
    }
    return 0;
}

