/*
Platform: Gfg
Problem Link: 
Problem Statement:
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.
*/

/* Complexities:
Time Complexity: O(2^N).
Space Complexity: O(N).
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool checkEqualPartition(int index, vector<int>& arr, int target) {
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
        
        bool include = checkEqualPartition(index+1, arr, target-arr[index]);
        bool exclude = checkEqualPartition(index+1, arr, target-0); 
        
        return include||exclude;
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
        
        return checkEqualPartition(0, arr, target);
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