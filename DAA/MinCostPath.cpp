#include <iostream>
#include <vector>
using namespace std;

struct Cell {
    int cost;
    string path; 
};

pair<int, string> minCostPath(int **cost, int m, int n) {
    Cell dp[m + 1][n + 1];
    dp[0][0] = {cost[0][0], "(0, 0)"};

    for (int i = 1; i <= m; i++) {
        dp[i][0].cost = dp[i - 1][0].cost + cost[i][0];
        dp[i][0].path = dp[i - 1][0].path + " -> (" + to_string(i) + ", 0)";
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j].cost = dp[0][j - 1].cost + cost[0][j];
        dp[0][j].path = dp[0][j - 1].path + " -> (0, " + to_string(j) + ")";
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j].cost <= dp[i][j - 1].cost && dp[i - 1][j].cost <= dp[i - 1][j - 1].cost) {
                dp[i][j].cost = dp[i - 1][j].cost + cost[i][j];
                dp[i][j].path = dp[i - 1][j].path + " -> (" + to_string(i) + ", " + to_string(j) + ")";
            } else if (dp[i][j - 1].cost <= dp[i - 1][j].cost && dp[i][j - 1].cost <= dp[i - 1][j - 1].cost) {
                dp[i][j].cost = dp[i][j - 1].cost + cost[i][j];
                dp[i][j].path = dp[i][j - 1].path + " -> (" + to_string(i) + ", " + to_string(j) + ")";
            } else {
                dp[i][j].cost = dp[i - 1][j - 1].cost + cost[i][j];
                dp[i][j].path = dp[i - 1][j - 1].path + " -> (" + to_string(i) + ", " + to_string(j) + ")";
            }
        }
    }

    return {dp[m][n].cost, dp[m][n].path};
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int **cost = new int *[m];
    for (int i = 0; i < m; i++)
        cost[i] = new int[n];

    cout << "Enter the cost matrix (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    auto [minCost, path] = minCostPath(cost, m - 1, n - 1);

    cout << "Minimum cost path: " << minCost << endl;
    cout << "Path: " << path << endl;

    for (int i = 0; i < m; i++)
        delete[] cost[i];
    delete[] cost;

    return 0;
}

