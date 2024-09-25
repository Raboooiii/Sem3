#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMoney(const vector<int>& coins){
	int n = coins.size();
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return coins[0];
	}
	if (n == 2){
		return max(coins[0],coins[1]);
	}
	
	vector<int> f(n);
	f[0] = coins[0];
	f[1] = max(coins[0], coins[1]);
	
	for (int i = 2; i < n; i++){
		f[i] = max(f[i - 1], f[i - 2] + coins[i]);
	}
	return f[n - 1];
}

int main(){
	int n;
	cout<<"How many coins are there :";
	cin>>n;
	vector <int> coins(n);
	cout<<"Enter the values of the coins :";
	for(int i = 0; i<n;i++){
		cin>>coins[i];
	}
	cout << "Maximum money that can be collected: " << maxMoney(coins) << endl;
	
	return 0;
}
