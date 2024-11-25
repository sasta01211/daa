#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    // Test case 1
    vector<int> weights1 = {1, 3, 4, 5};
    vector<int> values1 = {1, 4, 5, 7};
    int capacity1 = 7;
    cout << "Test case 1:" << endl;
    cout << "Maximum value: " << knapsack(weights1, values1, capacity1) << endl;

    // Test case 2
    vector<int> weights2 = {2, 3, 4};
    vector<int> values2 = {3, 4, 5};
    int capacity2 = 5;
    cout << "Test case 2:" << endl;
    cout << "Maximum value: " << knapsack(weights2, values2, capacity2) << endl;

    return 0;
}