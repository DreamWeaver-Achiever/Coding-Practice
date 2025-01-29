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
/* Time Complexity -> Exponential
*/
#include <bits/stdc++.h> 

int calculateMinimumElementsRquired(vector<int>& arrayElements, int targetSum) {
    //Base Case - 1
    if (targetSum == 0) {
        return 0;
    }
    //Base Case - 2
    if(targetSum<1) {
        return INT_MAX;
    }
    
    int mini = INT_MAX;
    //For loop to caluclateElements of array 'arrayElements' recursively.
    for(int i=0; i<arrayElements.size(); i++) {
        int answer = calculateMinimumElementsRquired(arrayElements, targetSum-arrayElements[i]); //Substract currently considered element in for loop i.e arrayElements[i] from totalSum.
        //Check for valid answer. We are considering INT_MAX as invalid answer on line-10; 
        if(answer != INT_MAX) {
            mini = min(mini, answer+1); //Current coin ke liye answer+1 consider karna padega. 
        }
    }
    return mini;
}
int minimumElements(vector<int> &arrayOfNumber, int targetSum)
{
    // Write your code here.
    int minimumElements = calculateMinimumElementsRquired(arrayOfNumber, targetSum);
    if(minimumElements == INT_MAX) {
        return -1;
    }
}