#include <iostream>
using namespace std;

int BinarySearch(int arr[], int LB, int UB, int x){
    if(LB > UB){
        return -1;
        }
    int mid = (LB + UB)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] > x){
        return BinarySearch(arr, LB, mid-1, x);
    }
    else{
        return BinarySearch(arr, mid+1, UB, x);
    }
    
}
int main(){
    int arr[100],n,x;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        }
    cout<<"Enter the element to search: ";
    cin>>x;
    int LB = 0, UB = n-1;
    int index = BinarySearch(arr, LB, UB, x);
    if(index == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<index<<endl;
    }
    return 0;
}
