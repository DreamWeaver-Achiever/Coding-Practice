//Problem Link -> https://www.naukri.com/code360/contests/striver-array-contest/9755146/problems/9622?leftPanelTabValue=PROBLEM
/*
Problem Statement -> 
You are given an array 'arr' of 'N' integers. Your task is to return the total number of distinct subarrays of 'arr' having 'k' odd elements.



Example :
If arr = [3,2,3], and k = 1 
then there are 4 subarrays with 1 odd elements:
[3], [3,2], [2,3] & [3].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1
5 2
2 1 1 1 4
Sample Output 1 :
4
Explanation for sample input 1 :
Following are 3 valid subarray:
[2,1,1], [1,1], [1,1], [1,1,4].
Sample Input 2 :
3 2
1 3 1
Sample Output 2 :
2
Constraints :
1 <= N <= 10^4
0 <= k <= N
1 <= arr[i] <= 10 ^ 5

Time Limit: 1sec

*/

int distinctSubKOdds(vector<int> &arr, int k)
{
	// Write your code here
	int n = arr.size();
    int count = 0;
    map<int, int> prefixOddCount;
    prefixOddCount[0] = 1;
    int currentOddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            currentOddCount++;
        }

        if (prefixOddCount.count(currentOddCount - k)) {
            count += prefixOddCount[currentOddCount - k];
        }

        prefixOddCount[currentOddCount]++;
    }

    return count;
}