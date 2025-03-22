#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> height;

    for(int i = 0; i < n; i++) {
        int stone;
        cin >> stone;
        height.push_back(stone);
    }

    vector<int> cost(n, 0);
    cost[1] = abs(height[1] - height[0]);

    for(int i = 2; i < n; i++) {
        cost[i] = min(cost[i-1] + abs(height[i] - height[i-1]),
                        cost[i-2] + abs(height[i] - height[i-2]));
    }

    cout<<cost[n-1]<<endl;
}