/*
Platform -> Code360
ProblemLink -> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&leftPanelTabValue=PROBLEM
Problem statement:
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation to Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
*/

/*Time Complexity -> O(n)
Space Complexity -> O(n)+O(n)*/
#include <bits/stdc++.h> 

int calculateMaxNonAdjacentSum(vector<int>& arrayList, int totalElements, vector<int>& dynamicArray) {
    //Base Case - 1
    if(totalElements<0) {
        return 0;
    }
    //Base Case - 2 -> Only one element is present
    if(totalElements==0) { 
        return arrayList[0];
    }

    //Step - 2 -> Check if elemtent != -1 i.e. results are already computed.
    if(dynamicArray[totalElements] != -1) {
        return dynamicArray[totalElements];
    }

    //Step - 3 -. Check if elements == -1 i.e. calculate result using recursion+Memoisation.
    int include = calculateMaxNonAdjacentSum(arrayList, totalElements-2, dynamicArray) + arrayList[totalElements];
    int exclude = calculateMaxNonAdjacentSum(arrayList, totalElements-1, dynamicArray);
    dynamicArray[totalElements] = max(include, exclude);
    
    return dynamicArray[totalElements];
}

int maximumNonAdjacentSum(vector<int> &arrayList){
    // Write your code here.
    int totalElements = arrayList.size(); 
    //Step-1 -> Declare one dynamicArray with size of totalElements and every element should -1.
    vector<int> dynamicArray(totalElements, -1);
    return calculateMaxNonAdjacentSum(arrayList,totalElements-1, dynamicArray);
}