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
Space Complexity -> O(2*maxWeight)
*/

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
	// Write your code here

	//Step - 1 -> Create two vectors for previous and current.
	vector <int> prev(capacity+1, 0);
	vector <int> curr(capacity+1, 0);

	//Step-2 -> Analyse base cases.
	for(int w=weight[0]; w<=capacity; w++) {
		if(weight[0]<=capacity) {
			prev[w]=value[0];
		} else {
			prev[w]=0;
		}
	} 

	//Step - 3 -> Take care of remaining calls.
	for(int index=1; index<n; index++) {
		for(int w=capacity; w>=0; w--) {
			int include =0;
			if(weight[index] <= w) {
				include = value[index]+prev[w-weight[index]];
			}
			int exclude = 0 + prev[w];
			curr[w]=max(exclude, include);
		}
		prev = curr;
	} 
	return prev[capacity];
}