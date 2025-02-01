/*
Platform -> Code360.
Problem Linke -> 
Problem statement: https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
7 5 2 2
8 3 3 3
Sample Output 1:
2
0
Explanation For Sample Input 1:

In the first test case, cut it into 2 parts of 5 and 2.

In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 
Sample Input 2:
2
7 3 2 2
8 1 4 4
Sample Output 2:
3
8
Explanation For Sample Input 2:
In the first test case, cut it into 3 parts of 3, 2 and 2.

In the second case, cut it into 8 parts of length 1.
*/

#include<limits.h>
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;
	for(int i=1; i<=n; i++) {
		if(i>=x && dp[i-x]>=INT_MIN) {
			dp[i] = max(dp[i], dp[i-x] + 1);
		}
		if(i>=y && dp[i-y]>=INT_MIN) {
			dp[i] = max(dp[i], dp[i-y] + 1);
		} 
		if(i>=z && dp[i-z]>=INT_MIN) {
			dp[i] = max(dp[i], dp[i-z] + 1);  
		}
	} 
	if(dp[n]<0) {
		return 0;
	} else {
		return dp[n];
	}
}