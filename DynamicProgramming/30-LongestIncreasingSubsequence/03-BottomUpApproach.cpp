/*
Platform: gfg
Problem Link: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
Problam Statement:
Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106
*/

/*
Time complexity ->  O(n^2).
Space complexity -> O(n^2).
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        // code here
         //Step-1 -> Create and declare a 2D array with length of n+1 and each element equal to 0.
        int n=arr.size();
        vector<vector<int>> dynamicArray(n+1, vector<int>(n+1, 0));
        
        // no need for base case as we have alreay set initial value to 0.
        
        for(int current=n-1; current>=0; current--) {
            for(int previous=current-1; previous>=-1; previous--) {
                int take=0; 
        if(previous==-1 || arr[current]>arr[previous]) {
            take = 1+dynamicArray[current+1][current+1];
        }
        
        //exclude
        int notTake=0+dynamicArray[current+1][previous+1]; 
       dynamicArray[current][previous+1] = max(take, notTake); 
            }
        } 
        return dynamicArray[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends