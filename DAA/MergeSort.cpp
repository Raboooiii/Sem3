#include <iostream>
using namespace std;

int MergeSort(int arr[], int LB, int UB){
    if(LB == UB){
        return 0;
    }
    int mid = (LB + UB)/2;
    MergeSort(arr, LB, mid);
    MergeSort(arr, mid+1, UB);
    int i = LB;
    int j = mid+1;
    int k = 0;
    int temp[UB-LB+1];
    while(i <= mid && j <= UB){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= UB){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = 0; i < UB-LB+1; i++){
        arr[i+LB] = temp[i];
    }
}

int main(){
    int arr[100],n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        }
    MergeSort(arr, 0, n-1);
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
        }
    return 0;
}
