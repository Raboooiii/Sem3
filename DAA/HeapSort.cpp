#include<iostream>
using namespace std;

    void swap(int A[], int a, int b) {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }

    void Heapify(int A[], int index, int n) {
        int max = index;
        int lChild = 2 * index + 1;
        int rChild = 2 * index + 2;

        if (lChild < n && A[lChild] > A[max])
            max = lChild;

        if (rChild < n && A[rChild] > A[max])
            max = rChild;

        if (max != index) {
            swap(A, index, max);
            Heapify(A, max, n);
        }
    }

    void HeapSort(int A[], int n) {
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(A, i, n);
        }

        
        for (int i = n - 1; i > 0; i--) {
            swap(A, 0, i);  
            Heapify(A, 0, i);  
        }
    }


void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements to the array : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    cout << "Original array: ";
    for (int i = 0; i<n; ++i) {
        cout << array[i] << " ";
    }

    HeapSort(array, n);
    
    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
