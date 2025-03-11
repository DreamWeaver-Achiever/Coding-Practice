/*
Platform: Gfg
Problem Link: 
Problem Statement:
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.
*/

/* Complexities:
Time Complexity: O(N * target) or O(N * (total/2)).
Space Complexity: O(N * target) or O(N * (total/2)).
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool checkEqualPartition(int index, vector<int>& arr, int target, vector<vector<int>>& dynamicArray) {
        int N = arr.size();
        //Base cases
        if(index >= N) {
            return 0;
        } 
        if(target < 0) {
            return 0;
        }
        if(target == 0) {
            return 1;
        } 
        
        //Step-2 -> Check if dynamicArray[index][target] != -1 i.e. element is already computed.
        if(dynamicArray[index][target] != -1) {
            return dynamicArray[index][target];
        }
        
        //Step-3 -> If element is not already computed then, compute it recursively.
        bool include = checkEqualPartition(index+1, arr, target-arr[index], dynamicArray);
        bool exclude = checkEqualPartition(index+1, arr, target-0, dynamicArray); 
        
        dynamicArray[index][target] = include||exclude;
        return dynamicArray[index][target];
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int total = 0;
        for(int i=0; i<arr.size(); i++) {
            total = total + arr[i];
        } 
        if(total & 1) {
            return 0;
        } 
        int target = total/2;
        
        //Step-1: Declare 2D array for index and target
        vector<vector<int>> dynamicArray(arr.size(),vector<int>(target+1, -1));
        
        return checkEqualPartition(0, arr, target, dynamicArray);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends