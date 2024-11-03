#include<iostream>
using namespace std;

void merge(int A[],int LB,int mid,int UB){
    int n1 = mid - LB + 1;
    int n2 = UB - mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = A[i+LB];
    }
    for(int j=0;j<n2;j++){
        R[j] = A[j+mid+1];
    }
    int i=0;
    int j=0;
    int k=LB;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[],int LB,int UB){
    if(LB < UB){
        int mid = LB + (UB - LB)/2;
        merge_sort(A,LB,mid);
        merge_sort(A,mid+1,UB);
        merge(A,LB,mid,UB);
    }
}

int main(){
    int n;
    cout<<"Enter Number of Elements :";
    cin>>n;
    int A[n];
    cout<<"Enter Elements :";
    for(int i=0;i<n;i++)
        cin>>A[i];
    merge_sort(A,0,n-1);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
