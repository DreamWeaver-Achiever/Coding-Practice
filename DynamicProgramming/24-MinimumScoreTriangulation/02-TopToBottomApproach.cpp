/*
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

 

Example 1:


Input: values = [1,2,3]

Output: 6

Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:


Input: values = [3,7,4,5]

Output: 144

Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:


Input: values = [1,3,1,4,1,5]

Output: 13

Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

 

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100

*/

/*
Time Complexity -> O(n^3).
Space Complexity -> O(n^2).
*/

class Solution {
public:
    int calculateMinScoreTriangulation(vector<int>& values, int i, int j, vector<vector<int>> &dynamicArray) {
        //Base case - when only two elements are present in the input array.
        if(i+1 == j) { 
            return 0;
        } 
        //Step-2 -> Check if element of an array is -1 i.e. result is result is already computed.
        if(dynamicArray[i][j] != -1) {
            return dynamicArray[i][j];
        } 
        //Step-3 -> If element of an array is equal to -1 then, result is not yet computed. Compute it recusively.
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) { 
            ans = min(ans, values[i]*values[j]*values[k]+calculateMinScoreTriangulation(values, i, k, dynamicArray)+calculateMinScoreTriangulation(values,k, j, dynamicArray));
        } 
        dynamicArray[i][j] = ans;
        return dynamicArray[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int length = values.size();
        //Step-1 -> Decalre an array with each element equal to -1 and size equal to n.
        vector<vector<int>> dynamicArray(length, vector<int>(length, -1));
        return calculateMinScoreTriangulation(values, 0, length-1, dynamicArray);
    }
};