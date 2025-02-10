/*
Platform: Code360.
Problem Link: 
Problem statement: https://www.naukri.com/code360/problems/tribonacci-sequence_3929491?leftPanelTabValue=PROBLEM
You are given an integer ‘N’. Your task is to find out the ‘N’th Tribonacci Number. ‘N’th number in the Tribonacci sequence is defined as Tn = T n - 1 + Tn - 2 + Tn - 3. Where T0 = 0, T1 = 1, T2= 1. Return the answer in mod of 109 + 7.

For Example :
You are given ‘N’ = 5, Here we know 0th, 1st and 2nd Tribonacci numbers are 0, 1 and 1 respectively. Therefore we can calculate the 3rd number as 0 + 1 + 1 = 2 and 4th number as 1 + 1 + 2 = 4 and 5th number as 1 + 2 + 4 = 7. Hence the answer is 7.
Follow Up :
Can you solve it in logarithmic time?
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 ≤ T ≤10
0 ≤ N ≤ 10^5

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function. 
Sample Input 1 :
2
5
2
Sample Output 1 :
7
1
Explanation for Sample Input 1:
For the first test case, ‘N’ = 5, Here we know 0th, 1st and 2nd Tribonacci numbers are 0, 1 and 1 respectively. Therefore we can calculate the 3rd number as 0 + 1 + 1 = 2 and 4th number as 1 + 1 + 2 = 4 and 5th number as 1 + 2 + 4 = 7. Hence the answer is 7.

For the second test case, ‘N’ = 2, Here, the second number in the Tribonacci sequence is already defined as 1. Hence the answer is 1.
Sample Input 2 :
2
0
9
Sample Output 2 :
0
81

*/
/*
Time Complexity -> O(n).
Space Complexity -> O(n).
*/
#include <bits/stdc++.h> 
#define mod 1000000007
int tribonacciSeq(int n) {
    // Write your code here.
    vector<long long>dynamicArray(n+3,0);
    dynamicArray[0]=0;
    dynamicArray[1]=1;
    dynamicArray[2]=1;
    for (int i=3;i<=n;i++)
    {
        dynamicArray[i]=(dynamicArray[i-1]+dynamicArray[i-2]+dynamicArray[i-3])%mod;
    }
    return dynamicArray[n];
}