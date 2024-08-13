#include<iostream>
using namespace std;

class heap {
public:
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
};

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heap h; 
    h.HeapHort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);

    return 0;
}
