#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<vector<int>> hodja(n, vector<int>(n, 1));
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            hodja[i][j] = (hodja[i-1][j] + hodja[i][j-1]) % 9929;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum += (hodja[i][j] * hodja[n-i-1][n-j-1]) % 9929;
            sum %= 9929;
        }
    }

    cout<<sum % 9929<<endl;
}