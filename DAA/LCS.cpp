#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100; 

int longestCommonSubsequence(char X[], char Y[], int m, int n) {
    int f[MAX][MAX] = {0}; 

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1; 
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]); 
            }
        }
    }

    return f[m][n];
}

int main() {
    char X[MAX], Y[MAX]; 
    
    cout << "Enter first string (X): ";
    cin >> X; 
    cout << "Enter second string (Y): ";
    cin >> Y; 
    int m = strlen(X); 
    int n = strlen(Y); 

    cout << "Length of LCS: " << longestCommonSubsequence(X, Y, m, n) << endl;
    return 0;
}
