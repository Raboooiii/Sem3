#include <iostream>
using namespace std;

int BinarySearch(int arr[], int LB, int UB, int x) {
    if(LB <= UB) {
        int mid = LB + (UB - LB) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        if(arr[mid] > x) {
            return BinarySearch(arr, LB, mid-1, x);
        }
        return BinarySearch(arr, mid+1, UB, x);
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> x;
    
    int index = BinarySearch(arr, 0, n-1, x);
    
    if(index == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index " << index;
    }
    
    return 0;
}
