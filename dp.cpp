#include<iostream>
using namespace std;

#pragma region Recursive BackTracking

int NthFibonacci_RB(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return NthFibonacci_RB(n-1) + NthFibonacci_RB(n-2);
}

#pragma endregion

#pragma region Top-Down DP

int NthFibonacci_TD(vector<int>& dp, int n)
{
    if(dp[n] != -1)
        return dp[n];

    return dp[n] = NthFibonacci_TD(dp, n-1) + NthFibonacci_TD(dp, n-2);
}

#pragma endregion

#pragma region Bottom-Up DP

int NthFibonacci_BU(int n)
{
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(1);

    for(int i = 2; i <= n; i++)
    {
        dp.push_back(dp[i-1] + dp[i-2]);
    }

    return dp[n];
}

#pragma endregion

#pragma region Buttom-Up with mo memory DP

int NthFibonacci_BU_NM(int n)
{
    int prev = 1, curr = 1, temp;

    for(int i = 2; i <= n; i++)
    {
        temp = prev;
        prev = curr;
        curr = curr + temp;
    }

    return curr;
}

#pragma endregion

int main()
{
    int n;
    cout<<"Enter n to find nth fib number: ";
    cin>>n;
    cout<<"Recursive BackTracking: "<<NthFibonacci_RB(n-1)<<endl;

    vector<int> dp(100, -1);
    dp[0] = 1; dp[1] = 1;
    cout<<"Top-Down DP: "<<NthFibonacci_TD(dp, n-1)<<endl;

    cout<<"Bottom-Up DP: "<<NthFibonacci_BU(n-1)<<endl;

    cout<<"Bottom-Up DP with no memory: "<<NthFibonacci_BU_NM(n-1)<<endl;
}