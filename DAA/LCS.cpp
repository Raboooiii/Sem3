#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100; // Maximum length for the strings

// Function to find the length of the longest common subsequence
int longestCommonSubsequence(char X[], char Y[], int m, int n) {
    int f[MAX][MAX] = {0}; // DP table initialized to 0

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1; // Characters match
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]); // Take max
            }
        }
    }

    return f[m][n]; // Return length of LCS
}

int main() {
    char X[MAX], Y[MAX]; // Input strings X and Y

    cout << "Enter first string (X): ";
    cin >> X; // Input the first string
    cout << "Enter second string (Y): ";
    cin >> Y; // Input the second string

    int m = strlen(X); // Length of string X
    int n = strlen(Y); // Length of string Y

    cout << "Length of LCS: " << longestCommonSubsequence(X, Y, m, n) << endl;
    return 0;
}
