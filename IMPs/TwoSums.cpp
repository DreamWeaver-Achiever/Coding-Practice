/*
Platform -> Code360
ProblemLink -> https://www.naukri.com/code360/problems/two-sum_839653?interviewProblemRedirection=true&search=two%20sum&attempt_status=COMPLETED
Problem statement:
You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.

Note:

We cannot use the element at a given index twice.
Follow Up:

Try to do this problem in O(N) time complexity. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.

Time Limit: 1 sec.
Sample Input 1 :
2
4 9
2 7 11 13
5 1
1 -1 -1 2 2
Sample Output 1:
2 7
-1 2
-1 2
Explanation for Sample 1:
For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.

For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
Sample Input 2 :
1
4 16
2 7 11 13
Sample Output 2 :
-1 -1
C++ (g++ 5.4)
1234567891011121314151617181920
#include<algorithm>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<pair<int,int>> answer;
	int start = 0;
	int end = n-1;
	while(start<end) {
		int sum = arr[start]+arr[end];

*/

#include<algorithm>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<pair<int,int>> answer;
	int start = 0;
	int end = n-1;
	while(start<end) {
		int sum = arr[start]+arr[end];
		if(sum==target) {
			answer.push_back({arr[start], arr[end]});
			start++;
			end--;
		} else if(sum>target) {
			end--;
		} else {
			start++;
		}
	}
	if(answer.empty()) {
		answer.push_back({-1, -1});
	}
	return answer;
}
