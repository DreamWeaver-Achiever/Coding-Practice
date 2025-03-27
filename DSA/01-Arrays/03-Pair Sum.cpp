//Problem Link : https://www.naukri.com/code360/problems/pair-sum_1171154?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	// Write your code here. 
	int i=0,j=n-1,count=0;
	while(i<j)
	{
		if((arr[i]+arr[j])==target)
		{
			++count;
			++i;
			--j;
		}
		else if((arr[i]+arr[j])<target)
		{
			++i;
		}
		else if((arr[i]+arr[j])>target)
		{
			--j;
		}
	}
	if(count==0)
	{
		return -1;
	}
	return count;
}