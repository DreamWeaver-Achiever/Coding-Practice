//Problem Statement -> 
/*
Problem statement

Send feedback

You are given an array ‘NUMS’ of length ‘N’. You are also given an integer ‘TARGET’.



Return an array of all the unique quadruplets [ ‘NUMS[ a ]’, ‘NUMS[ b ]’, ‘NUMS[ c ]’, ‘NUMS[ d ]’ ] with the following conditions:



i. 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.

ii. NUMS[ a ] + NUMS[ b ] + NUMS[ c ] +NUMS[ d ] = TARGET



Return the array in any order.



Note:



(NUMS[ a ], NUMS[ b ], NUMS[ c ], NUMS[ d ]), (NUMS[ a ], NUMS[ d ], NUMS[ c ], NUMS[ b ]), (NUMS[ a ], NUMS[ c ], NUMS[ b ], NUMS[ d ])... all of them are treated or considered the same quadruplets.



Two quadruplets are different if there is any integer in one quadruplet which is not in the other.



The solution will be verified by the number of valid quadruplets returned. In the output, only the number of valid quadruplets will be printed.



Example:

Input: ‘N’ = 5, ‘TARGET’ = 5, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]



Output: 1.



There is only one unique quadruplet with sum = 5 and that is [1, 2, 1, 1].

Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1:

6 8

2 2 2 2 1 3

Sample Output 1 :

2

Explanation Of Sample Input 1:

(2+2+2+2) = (2+2+1+3) = 4.

Sample Input 2:

4 4

1 1 1 0

Sample Output 2 :

0

Constraints :

4 <= N <= 100

-10^6 <= NUMS[ i ] <= 10^6

-10^6 <= TARGET <= 10^6





Time Limit: 1 sec => vector<vector<int>>
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSumOptimized(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> unique_quadruplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    unique_quadruplets.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return vector<vector<int>>(unique_quadruplets.begin(), unique_quadruplets.end());
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> result = fourSumOptimized(nums, target);
    cout << result.size() << endl;

    return 0;
}