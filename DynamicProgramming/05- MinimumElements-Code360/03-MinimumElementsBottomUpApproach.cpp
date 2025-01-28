/*
Platform -> Code360
ProblemLink ->https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0
Problem statement:
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 15
1 <= nums[i] <= (2^31) - 1
1 <= X <= 10000

All the elements of the “nums” array will be unique.
Time limit: 1 sec
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample output 1 :
 3
 0
Explanation For Sample Output 1:
For the first test case,
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
For the second test case
To reach X = 0, you don’t need to take any elements from the array.
The sum is already 0, so the total number of elements used is 0.
Sample Input 2 :
2
3 4
12 1 3
2 11
2 1
Sample output 2 :
2
6 
*/

/* Time Complexity -> O(arrayElements.size()* targetSum)
   Space Complexity -> O(targetSum) -> The dynamicArray vector is used to store the results of subproblems. The size of dynamicArray is targetSum + 1. Therefore, the space complexity is determined by the size of this array, which is O(X).
*/
#include <bits/stdc++.h> 

int minimumElements(vector<int> &arrayOfNumber, int targetSum)
{
    vector<int> dynamicArray(targetSum+1, INT_MAX);
    dynamicArray[0]=0;

    for(int i = 1; i<=targetSum; i++) { //Solve for amount from 1 to targetSum
        for(int j=0; j<arrayOfNumber.size(); j++) {
            if(i-arrayOfNumber[j] >= 0 && dynamicArray[i-arrayOfNumber[j] != INT_MAX]) {
                dynamicArray[i] = min(dynamicArray[i], 1+dynamicArray[i-arrayOfNumber[j]]);
            }
        }
    } 
    if(dynamicArray[targetSum] == INT_MAX) {
        return -1;
    }
    return dynamicArray[targetSum];
}