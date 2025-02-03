/*
Platform -> Code360
Problem Link -> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&leftPanelTabValue=PROBLEM
Problem statement:
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.



All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.



You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.



Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.


For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5 x 10 ^ 3
1 <= ARR[i] <= 10 ^ 9

Time limit: 1 sec.
Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4
Explanation of Input 1:
(i) Mr. X has only one house to rob, but with no money.

(ii) Mr. X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses (remember, it’s a circular street). So, he’ll rob only house 2 (money = 3) with a maximum value

(iii) Mr. X will get maximum value when he robs house 2 (money = 3) and then robs house 4 (money = 1) i.e. 4 units of money.
Sample Input 2:
3
5
1 5 1 2 6
3
2 3 5
4
1 3 2 0
Sample Output 2:
11
5
3
*/

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

    //Create an array with legnth same as totalLength and assign each element to 0.
    vector<int> dynamicArray(totalElements, 0);
    
    //Write base case
    dynamicArray[0] = arrayList[0];

    //Convert recursive call logic of top-down approach into tabulation using for loop.
    for(int i=1; i<totalElements; i++) {
        int include = dynamicArray[i-2]+arrayList[i];
        int exclude = dynamicArray[i-1];
        dynamicArray[i] = max(include, exclude);
    } 
    return dynamicArray[totalElements-1];
}