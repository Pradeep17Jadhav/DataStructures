#include <bits/stdc++.h>
using namespace std;

//0 1 1 2 3 5 8 13 21...

int recursive(int num) {
	if(num == 0) return 0;
    if(num == 1) return 1;
    return recursive(num-1) + recursive(num-2);
}

int dynamicprogramming(vector<int> &dp, int num) {
	if(dp[num] != -1) 
		return dp[num];
	
	dp[num] = dynamicprogramming(dp, num-1) + dynamicprogramming(dp, num-2);
	return dp[num];
}
	
int tabulation(vector<int> &dp, int num) {
	for(int i = 2; i <= num; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	return dp[num];
}

int optimized(int num) {
	int pre2 = 0;
	int pre1 = 1;
	if(num == 0) return pre2;
	if(num == 1) return pre1;

	int curr;
	
	for(int i = 2; i <= num; i++) {
		curr = pre1 + pre2;
		pre2 = pre1;
		pre1 = curr;
	}
	return pre1;
}

int main() {
	int num, res;
	cout << "Enter fibonacci number : ";
	cin >> num;
	
	//Recursive solution
	res = recursive(num);
	cout << "Recursive Answer is: " << res << endl;

	//Dynamic programming 
	//Bottom up (Memoization)
	vector<int> dp(num+1, -1);
	dp[0] = 0;
	dp[1] = 1;
    res = dynamicprogramming(dp, num);
	cout << "Memoization Answer is: " << res << endl;
	
	//Dynamic Programming
	//Top down (Tabulation)
	dp.clear();
	dp[0] = 0;
	dp[1] = 1;
	res = tabulation(dp, num);
	cout << "Tabulation Answer is: " << res << endl;
	
	//Dynamic Programming
	//Optimized soltution
	res = optimized(num);
	cout << "Optimized Answer is: " << res << endl;
	
	return 0;
}
