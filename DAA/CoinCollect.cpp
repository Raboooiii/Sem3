#include <iostream>
using namespace std;

void coin_collecting(int C[][100], int n, int m) {
    int F[100][100] = {0}; 
    F[0][0] = C[0][0];

    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + C[i][0];
    }
	
    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j - 1] + C[0][j];
    }
	
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    cout << "Maximum coins collected: " << F[n - 1][m - 1] << endl;
}

int main() {
    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    int C[100][100]; 

    cout << "Enter the coin values (matrix):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j]; 
        }
    }

    coin_collecting(C, n, m);

    return 0;
}
