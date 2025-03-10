/*
Platform: GFG
Problem Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1
Problem Statement: 
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.
*/

/*
Time Complexity: O(dices * target * faces).
Space Complexity: O(target).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int noOfWays(int faces, int dices, int target) {
        //Only two rows for d and d-1 are enough.
        // prev = dynamicArray[0]
        vector<long long int> previous(target+1, 0);
        vector<long long int> current(target+1, 0);
        
        //Only single base case is enough.
        previous[0]=1; 
        
        for(int d=1; d<=dices; d++) {
            for(int t=1; t<=target; t++) { 
                long long ans=0; 
                for(int i=1; i<=faces; i++) { 
                    if(t-i >= 0) { 
                        ans = ans +previous[t-i]; 
                    } 
                    
                } 
                current[t] = ans;
            }
            previous = current;
        }
        return previous[target];
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends