// Link: https://leetcode.com/problems/partition-array-according-to-the-given-pivot/
/* description : 
    Given an array nums of non-negative integers and an integer pivot, 
    sort the array in such a way that all values less than pivot come before pivot, 
    and all values greater than or equal to pivot come after it.
    It is guaranteed that the relative order of the values in the lower and higher partitions should remain the same.
    Note: The partitioning should be in-place.
*/
import java.util.*;

// 3 pass solution with O(n) time complexity with extra space
public class PartitionArrayAccordingToGivenPivot {
    class Solution {
        public int[] pivotArray(int[] nums, int pivot) {
            ArrayList<Integer> list1 = new ArrayList<>();
            int pCount = 0;
            for(int n : nums){
                if(n < pivot){
                    list1.add(n);
                }
                if( n == pivot ) pCount++;
            }
            ArrayList<Integer> list2 = new ArrayList<>();
            for(int n : nums){
                if(n > pivot){
                    list2.add(n);
                }
            }
            int[] sol = new int[nums.length];
            for(int i = 0; i < list1.size(); i++){
                sol[i] = list1.get(i);
            }
            int index = list1.size();
            for(int i = 0; i < pCount; i++){
                sol[index++] = pivot;
            }
            
            for(int i = 0; i < list2.size(); i++){
                sol[index++] = list2.get(i);
            }
            return sol;
    
        }
    }
}

// 1 pass solution with O(n) time complexity
class PartitionArrayAccordingToGivenPivotOnePass {
    class Solution {
        public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] result = new int[n];
        
        // Index for filling the result array
        int leftIndex = 0;
        
        // First pass: Add all elements less than pivot
        for (int num : nums) {
            if (num < pivot) {
                result[leftIndex++] = num;
            }
        }
        
        // Second pass: Add all elements equal to pivot
        for (int num : nums) {
            if (num == pivot) {
                result[leftIndex++] = num;
            }
        }
        
        // Third pass: Add all elements greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                result[leftIndex++] = num;
            }
        }
        
        return result;
    }
}
}
