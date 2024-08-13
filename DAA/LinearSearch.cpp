#include <iostream>
using namespace std;

int LinearSearch(int A[], int x,int n){
    for(int i=0;i<n;i++){
        if(A[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter Number Of Elements :"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter Elements :"<<endl;
    for(int i= 0;i<n;i++){
        cin>>A[i];
    }
    int x;
    cout<<"Enter Value :"<<endl;
    cin>>x;
    int index = LinearSearch(A,x,n);
    if(index != -1){
        cout<<"Element found at index "<<index<<endl;
    }
    else{
        cout<<"Element not Found"<<endl;
    }
    return 0;
}
