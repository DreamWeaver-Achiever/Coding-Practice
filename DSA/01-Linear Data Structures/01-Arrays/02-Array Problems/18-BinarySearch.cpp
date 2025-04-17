//Problem Link -> https://www.naukri.com/code360/problems/binary-search_972?leftPanelTabValue=PROBLEM

int search(vector<int> &nums, int target) {
    // Write your code here.
    int beg=0, mid, found=0, end=nums.size()-1;
    while(beg<=end) {
        mid = beg + (mid-beg)/2;

        if(nums[mid]==target) {
            found=1;
            return mid;
        } else if (nums[mid]>target) {
            end = mid-1;
        } else if(nums[mid]<target) {
            beg = mid+1;
        }
    } 
    if((beg>end) && (found==0)) {
        return -1;
    } 
}