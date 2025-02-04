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
Space Complexity -> O(n*maxWeight)
*/

#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
	//Step - 1 -> Create a 2D array.
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	//Step - 2 -> Base case logic.
	for(int w = weight[0]; w<=capacity; w++) {
		if(weight[0]<=capacity) {
			dp[0][w]=value[0];
		} else {
			dp[0][w]=0;
		}
	}

	//Step - 3 -> Remaining recursive calls.
	for(int index = 1; index<n; index++) {
		for(int w=0; w<=capacity; w++) {
			int include = 0;
			if(weight[index]<=w) {
				include = value[index]+dp[index-1][w-weight[index]];
			}
			int exclude = 0+dp[index-1][w];
			dp[index][w]=max(exclude, include);
		}
	}
	return dp[n-1][capacity];
	
}