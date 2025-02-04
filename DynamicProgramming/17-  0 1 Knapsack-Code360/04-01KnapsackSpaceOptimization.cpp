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
		for(int w=0; w<=capacity; w++) {
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