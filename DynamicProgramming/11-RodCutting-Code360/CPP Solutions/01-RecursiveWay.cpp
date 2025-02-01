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

/*
Time Complexity -> Exponential.
*/

#include<limits.h> // need to import this as we are using INT_MAX

int maxSegments(int rodLength, int x, int y, int z) {

	//Base case - 1
	if(rodLength==0) {
		return 0;
	} 

	//Base case - 2; to handle the cases where subtraction will be negative integer.
	if(rodLength<0) {
		return INT_MAX;
	} 

	int startWithFirst = maxSegments((rodLength-x), x, y, z)+1;
	int startWithSecond = maxSegments((rodLength-y), x, y, z)+1;
	int startWithThird = maxSegments((rodLength-z), x, y, z)+1;

	int maximumCuts = max(startWithFirst, max(startWithSecond, startWithThird));
	return maximumCuts;
}

int cutSegments(int rodLenght, int x, int y, int z) {
	// Write your code here.
	int maximumCuts = maxSegments(rodLenght, x, y, z);

	if(maximumCuts<0) {
		return 0;
	} else {
		return maximumCuts;
	}
}