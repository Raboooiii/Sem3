#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinCollect(vector <int>& coins, int amount){
	const int INF = 10000;
	vector <int> f(amount + 1, INF);
	vector <int> usedCoin(amount + 1, -1);
	f[0] = 0;
	
	for (int coin : coins){
		for (int i = coin; i <= amount; i++){
			if (f[i - coin] + 1 < f[i]) {
                	f[i] = f[i - coin] + 1;
                	usedCoin[i] = coin;
            		}
		}
	}
	cout << "Coins used to form the amount " << amount << ": ";
    	int remainingAmount = amount;
    	while (remainingAmount > 0) {
        	int coin = usedCoin[remainingAmount];
        	cout << coin << " ";
        	remainingAmount -= coin;
    	}
    	cout << endl;
	return f[amount];
	
}
int main(){
	int n, amount;
	cout<<"How many coins are there :";
	cin>>n;
	vector <int> coins(n);
	cout<<"Enter the values of the coins :";
	for(int i = 0; i<n;i++){
		cin>>coins[i];
	}
	cout<<"What is the amount ? :";
	cin>>amount;
	
	cout<<"The min no. of coins needed to get the amount is "<<coinCollect(coins, amount)<<endl;
	
	return 0;
}
