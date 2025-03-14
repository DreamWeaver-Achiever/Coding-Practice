/*
Platform-> Leetcode.
Problem Link -> 
Problem Statement -> 
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1]. 
*/

/*
Complexities -> 
Time Complexity: O(n).
Space Complexity: O(n).
*/

class Solution {
    public:
        int minSwap(vector<int>& nums1, vector<int>& nums2) {
            nums1.insert(nums1.begin(), -1);
            nums2.insert(nums2.begin(), -1);
            int n = nums1.size();
            vector<vector<int>> dp(n+1, vector<int>(2, 0));
            for(int index=n-1; index>=1; index--) {
                for(int swapped=1; swapped>=0; swapped--) { //This for loop will give constants complexity so no need to consider this for loop while calculating time complexity.
                    // If elements of an array are not yet computed then calculate them recursively.
                    int ans = INT_MAX;
                    int previous1 = nums1[index-1];
                    int previous2 = nums2[index-1];
    
                    //Check if indexes are already swapped.
                    if(swapped) {
                        swap(previous1, previous2);
                    }
    
                    //No-swap 
                    if(nums1[index]>previous1 && nums2[index]>previous2) { 
                        ans = dp[index+1][0]; 
                        } 
    
                    //Swap 
                    if(nums1[index]>previous2 && nums2[index]>previous1) { 
                        ans = min(ans, 1+dp[index+1][1]); 
                        } 
                        dp[index][swapped] = ans;
                }
            } 
            return dp[1][0];
    
        }
    };