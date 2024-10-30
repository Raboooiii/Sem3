#include <iostream>
using namespace std;

void coin_row (int C[],int n){
    int F[n],B[n];
    F[0] = 0;
    F[1] = C[1];
    B[0] = 0;
    B[1] = 1;
    for(int i =2;i<n;i++){
        if(C[i]+F[i-2]>F[i-1]){
            B[i] = i-2;
        }
        else{
            B[i] = i-1;
        }
        F[i] = max(C[i]+F[i-2],F[i-1]);
    }
    cout<<"Max Value :"<<F[n-1]<<endl;
    cout<<"Chosen Coins: ";
    for(int i=n;i>=0;){
        if(B[i] == i-2){
            cout<<C[i]<<" ";
            i = i-2;
        }
        else if(i==1){
            cout<<C[i];
            i = i-1;
        }
        else{
            i--;
        }
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number Of Coins:";
    cin>>n;
    int A[n];
    cout<<"Enter Coins :";
    A[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    coin_row(A,n+1);
    return 0;
}
