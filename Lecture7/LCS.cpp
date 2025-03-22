#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int size1, size2;
    cin>>size1;

    vector<int> s1, s2;
    for(int i = 0; i < size1; i++)
    {
        int num;
        cin>>num;
        s1.push_back(num);
    }

    cin>>size2;

    for(int i = 0; i < size2; i++)
    {
        int num;
        cin>>num;
        s2.push_back(num);
    }

    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    for(int i = 1; i <= size1; i++)
    {
        for(int j = 1; j <= size2; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    vector<int> ans;
    int i = size1, j = size2;

    while(dp[i][j] != 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans.push_back(s2[j-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    
    for(int i = ans.size()-1; i >= 0; i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}