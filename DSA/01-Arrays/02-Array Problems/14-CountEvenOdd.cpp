//Problem Link -> https://www.naukri.com/code360/contests/striver-array-contest/9755146/problems/7622?leftPanelTabValue=PROBLEM
//Problem statement -> 
/*
You have been given an array/list of integers 'ARR' of size 'N'. Your task is to find two things-

1. The number of elements that are occurring an Odd number of times.

2. The number of elements that are occurring Even a number of times.

For Example:
ARR = [2, 1, 2, 1, 5, 5, 2]    
Output: 1 2 

2 occurs three(odd) times.
1 occurs two(even) times.
5 occurs two(even) times.

So, the total 1 element is occurring an odd number of times and 2 elements are occurring an even number of times.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^2
0 <= N <= 5 * 10^3
1 <= ARR[i] <= 10^9

Time Limit: 1 sec
Output Format:
For each test case, print two single space-separated integers representing the number of odd occurring elements and number of even occurring elements respectively.

The output of each test case will be printed a separate line.
Note:

You are not required to print the output, it has already been taken care of. Just implement the function. 
*/
#include <bits/stdc++.h> 
vector<int> countEvenOdd(vector<int> &arr, int n)
{
	//  Write your code here.
   std::map<int, int> counts;
    for (int i=0; i<n;i++) {
        counts[arr[i]]++;
    }

    int oddCount = 0;
    int evenCount = 0;

    for (auto const& pair : counts) {
        int key = pair.first;
        int val = pair.second;
        if (val % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    return {oddCount, evenCount};
}
