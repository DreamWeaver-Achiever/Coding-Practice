/*
Platform: gfg
Problem Link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
Problem Statement:
Largest square formed in a matrix
Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: mat = [[1, 1], 
              [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: mat = [[0, 0], 
              [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Constraints:
1 ≤ mat.size(), mat[i].size() ≤ 500
0 ≤ mat[i][j] ≤ 1 


*/

/*
Complexities:
Time Complexity -> O(n^3).
Space Complexity -> O(n).
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public: 
    int solve(vector<vector<int>> mat,  int i, int j, int &maxi) {
        //Base case -> i & j should be within the size of mat.
        if((i>=mat.size()) ||(j>=mat[0].size())) {
            return 0;
        } 
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat,i+1, j, maxi);
        
        if(mat[i][j] == 1) {
            int ans = 1+min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        } else {
            return 0;
        }
    }
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int maxi=0;
        solve(mat, 0, 0, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends