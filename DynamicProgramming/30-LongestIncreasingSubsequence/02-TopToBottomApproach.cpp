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
Time complexity ->  O(n^2) i.e. exponential.
Space complexity -> O(n^2) 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int calculateLIS(vector<int>& arr, int current, int previous, vector<vector<int>>& dynamicArray) {
        //base case
        int n = arr.size();
        if(current==n) {
            return 0;
        } 
        
        //Step-2 -> Check if results are already computed.
        if(dynamicArray[current][previous+1] != -1) {
            return dynamicArray[current][previous+1];
        }
        
        //Step-3 -> If results are not alreay computed then calculate it recursively.
        //include
        int take=0; 
        if(previous==-1 || arr[current]>arr[previous]) {
            take = 1+calculateLIS(arr, current+1, current, dynamicArray);
        }
        
        //exclude
        int notTake=0+calculateLIS(arr, current+1, previous, dynamicArray); 
        return dynamicArray[current][previous+1] = max(take, notTake); //previous+1 is required as we are also dealing with -1 values for this attribute.
    }
    int lis(vector<int>& arr) {
        // code here
        //Step-1 -> Create and declare a 2D array with length of n+1 and each element equal to -1.
        int n=arr.size();
        vector<vector<int>> dynamicArray(n, vector<int>(n+1, -1));
        return calculateLIS(arr, 0, -1, dynamicArray);
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