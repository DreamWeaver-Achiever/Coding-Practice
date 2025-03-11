/*
Platform: Gfg
Problem Link: 
Problem Statement:
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.
*/

/* Complexities:
Time Complexity: O(N * total).
Space Complexity: O(N * total).
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int total = 0;
        for(int i=0; i<arr.size(); i++) {
            total = total + arr[i];
        } 
        if(total & 1) {
            return 0;
        } 
        int N = arr.size();
        //Base cases
       //Step-1: Declare 2D array for index and target
        vector<vector<int>> dynamicArray(N+1,vector<int>(total+1, 0));
        for(int i=0; i<=N; i++) {
            dynamicArray[i][0] = 1;
        }
        
        //index is running from n-1 to 0 
        // target should go from 0 to total/2
        for(int index=N-1; index>=0; index--) {
            for(int target=0; target<=total/2; target++) {
                bool include = 0;
                if(target-arr[index]>=0) {
                    include = dynamicArray[index+1][target-arr[index]];
                } 
                bool exclude = dynamicArray[index+1][target-0];
                dynamicArray[index][target] = include || exclude;
                
            }
        } 
        return dynamicArray[0][total/2];
};
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