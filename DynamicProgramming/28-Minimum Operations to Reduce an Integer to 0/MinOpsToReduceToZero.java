// Link - https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
    public int minOperations(int n) {
        
        // if the curr value is a power of 2, there is only one subtraction needed
        if ((n & (n - 1)) == 0)
            return 1;

        // highest power of 2 just greater than current value - current value
        int diff1 = (1 << ((int)(Math.log(n) / Math.log(2)) + 1)) - n;

        // current value - highest power of 2 just smaller than current value
        int diff2 = n - (1 << (int)(Math.log(n) / Math.log(2)));
		
		// we add 1 in both the cases
        return Math.min(minOperations(diff1), minOperations(diff2)) + 1;

    }
}