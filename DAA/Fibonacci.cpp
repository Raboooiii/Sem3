#include <iostream>
using namespace std;

void fibonacci(int n) {
    int f1 = 0, f2 = 1, F;
    cout << "Fibonacci Series: " << f1 << " " << f2 << " ";
    for (int i = 1; i <= n-2; ++i) {
        F = f1 + f2;
        cout << F << " ";
        f1 = f2;
        f2 = F;
    }
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    fibonacci(n);
    return 0;
    cout << endl;
}
