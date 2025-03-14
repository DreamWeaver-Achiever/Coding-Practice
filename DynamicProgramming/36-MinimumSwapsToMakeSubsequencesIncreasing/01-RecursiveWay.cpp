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
Time Complexity: O(2^n).
Space Complexity: O(n).
*/
class Solution {
    public:
        int calculateMinSwaps(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
            //Base case
            if(index==nums1.size() || index==nums2.size()) { //index went our of nums1.size() || nums2.size().
                return 0;
            } 
            int ans = INT_MAX;
            int previous1 = nums1[index-1];
            int previous2 = nums2[index-1];
    
            //Check if indexes are already swapped.
            if(swapped) {
                swap(previous1, previous2);
            } 
            //No-swap 
            if(nums1[index]>previous1 && nums2[index]>previous2) {
                ans = calculateMinSwaps(nums1, nums2, index+1, 0);
            }
            //Swap
            if(nums1[index]>previous2 && nums2[index]>previous1) {
                ans = min(ans, 1+calculateMinSwaps(nums1, nums2, index+1, 1));
            } 
            return ans;
        }
        int minSwap(vector<int>& nums1, vector<int>& nums2) {
            //Initialize arrays with '-1'.
            nums1.insert(nums1.begin(), -1);
            nums2.insert(nums2.begin(), -1); 
    
            bool swapped = 0;
            return calculateMinSwaps(nums1, nums2, 1, swapped);
    
        }
    };