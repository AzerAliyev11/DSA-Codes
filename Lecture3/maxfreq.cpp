#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    vector<int> freqArray(10000, 0);
    vector<stack<int>> vectorStack;

    string command;
    while(cin >> command)
    {
        if(command == "push")
        {
            int num;
            cin >> num;
            if(vectorStack.size() <= freqArray[num])
            {
                vectorStack.push_back(stack<int>());
            }
            vectorStack[freqArray[num]].push(num);
            freqArray[num]++;
        }
        else
        {
            int vectorSize = vectorStack.size();
            for(int i = vectorSize - 1; i >= 0; i--)
            {
                if(!vectorStack[i].empty())
                {
                    int topElm = vectorStack[i].top();
                    cout<<topElm << endl;
                    freqArray[topElm]--;
                    vectorStack[i].pop();
                    break;
                }
            }
        }
    }
}