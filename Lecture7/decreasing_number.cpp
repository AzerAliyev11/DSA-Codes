#include <iostream>
#include <vector>
using namespace std;

int dec_num(int n, vector<int>& dp) {
    if(dp[n] != -1)
        return dp[n];

    if(n%3 != 0 && n%2 != 0) {
        return dp[n]=dec_num(n-1, dp) + 1;
    }
    else if(n%3 == 0 && n%2 != 0) {
        return dp[n] = min(dec_num(n/3, dp), dec_num(n-1, dp)) + 1;
    }
    else if(n%2 == 0 && n%3 != 0) {
        return dp[n] = min(dec_num(n/2, dp), dec_num(n-1, dp)) + 1;
    }
    else {
        //return dec_num(n/3) + 1;
        return dp[n] = min(dec_num(n/3, dp), min(dec_num(n/2, dp), dec_num(n-1, dp))) + 1;
        //min(a, min(b,c))
    }
}

int main() {
    int n;

    vector<int> dp(1000001, -1);
    dp[1] = 0;
    while(cin >> n) {
        cout<<dec_num(n, dp)<<endl;
    }
}