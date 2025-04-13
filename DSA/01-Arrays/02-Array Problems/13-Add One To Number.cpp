//Problem Link -> https://www.naukri.com/code360/contests/striver-array-contest/9755146/problems/8410?leftPanelTabValue=PROBLEM
//Problem statement -> 
/*
Given a non-negative number represented as an array of digits, you have to add 1 to the number, i.e, increment the given number by one.

The digits are stored such that the most significant digit is at the starting of the array and the least significant digit is at the end of the array.

For Example
If the given array is {1,5,2}, the returned array should be {1,5,3}.
Note
Input array can contain leading zeros, but the output array should not contain any leading zeros (even if the input array contains leading zeroes).
For Example: 
If the given array is {0,2}, the returned array should be {3}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= T <= 10
1 <= N <= 5 * 10^4
0 <= Arr[i] <= 9

Where Arr[i] is the i-th digit in the number.
Sample Input 1
3
3
1 2 3
2
9 9
1
4
Sample Output 1
1 2 4
1 0 0
5
*/
#include <bits/stdc++.h> 
vector<int> addOneToNumber(vector<int> arr)
{
    // Write your code here
     int n = arr.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        arr[i] += carry;
        carry = arr[i] / 10;
        arr[i] %= 10;
        if (carry == 0) {
            break;
        }
    }
    if (carry > 0) {
        arr.insert(arr.begin(), carry);
    }
    // Remove leading zeros
    int i = 0;
    while (i < arr.size() - 1 && arr[i] == 0) {
        arr.erase(arr.begin());
    }
    return arr;
}