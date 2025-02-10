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
Time Complexity -> O(n^2).
Space Complexity -> O(1).
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(vector<vector<int>>& matrix) {
        // code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        int prev = 0; 
        int maxi = 0;

         int count=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]==1 && i-1>=0 && j-1>=0)
                {
             matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                }
                count=max(matrix[i][j],count);
            }
        }
        return count;
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