/*
Platform -> gfg
Problem Link -> https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1
Problem Statement -> Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

Examples:

Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
Expected Time Complexity: O(n * sqrt(n))
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 104


*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MinSquares(int n) {
        // Code here
        //Base case - 1 
        if(n==0) {
            return 0;
        }
        int ans = n;
        for(int i=1; i*i<=n; i++) {
            ans = min(ans, 1+MinSquares(n-(i*i)));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends