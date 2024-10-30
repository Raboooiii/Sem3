#include <iostream>
using namespace std;

const int MAX_ITEMS = 100; // Maximum number of items
const int MAX_CAPACITY = 1000; // Maximum capacity of the knapsack

// Function to solve the 0/1 Knapsack Problem
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1] = {0}; // DP table initialized to 0

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Item cannot be included
            }
        }
    }

    return dp[n][capacity]; // Return the maximum value that can be achieved
}

int main() {
    int n, capacity;
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}