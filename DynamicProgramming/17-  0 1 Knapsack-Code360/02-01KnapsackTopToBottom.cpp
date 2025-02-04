/*
Platform -> Code360
Playlist -> https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
Problem Statement: 
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/

/* Complexities -> 
Time Complexity -> 
Space Complexity -> 
*/

#include <bits/stdc++.h> 

int solve (vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>>& dp){
	//Base case 
	//If only 1 item to steal, then just compare its weight with knapsack capacity
	if(index==0) {
		if(weight[0] <= capacity) {
			return value[0];
		} else {
			return 0;
		}
	}

	//Step - 2 -> Check if dp[index][capacity] != -1 i.e. if already computed.
	if(dp[index][capacity] != -1) {
		return dp[index][capacity];
	}

	//Step - 3 -> If dp[index][capacity] == -1 then, compute it recursively.
	int include=0;
	if(weight[index]<=capacity) {
		include = value[index] + solve(weight, value, index-1, capacity-weight[index], dp);
	} 
	int exclude = 0+solve(weight, value,index-1, capacity, dp);
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	//Step-1 -> Declare 2D array of index(n in this case) and maxWeight. And assign its each value to -1.
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
	
}