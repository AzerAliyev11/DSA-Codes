#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int numOfSoldiers;
    cin >> numOfSoldiers;

    stack<pair<int, int>> soldiersStack; //height, index

    for(int i = 0; i < numOfSoldiers; i++)
    {
        int soldierHeight;
        cin >> soldierHeight;

        if(soldiersStack.empty() || soldierHeight < soldiersStack.top().first)
        {
            if(soldiersStack.empty())
                cout<<-1<<" ";
            else
                cout << soldiersStack.top().second<<" ";
                
            soldiersStack.push({soldierHeight, i});
        }
        else
        {
            while(!soldiersStack.empty() && soldiersStack.top().first <= soldierHeight)
            {
                soldiersStack.pop();
            }

            if(soldiersStack.empty())
                cout<<-1<<" ";
            else
                cout << soldiersStack.top().second<<" ";

            soldiersStack.push({soldierHeight, i});
        }
    }
}