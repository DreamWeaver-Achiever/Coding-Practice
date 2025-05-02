//Problem Link -> https://www.naukri.com/code360/guided-paths/data-structures-algorithms-new/content/662513/offering/10676522?leftPanelTabValue=PROBLEM
int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int mid, beg=0, end=n-1;
    while(beg<=end) {
        mid = beg + (end-beg)/2;
        if(input[mid]==val) {
            return mid;
        } else if (input[mid]>val) {
            end = mid-1;
        } else if (input[mid]<val) {
            beg = mid+1;
        } 
    } 
   return -1;
}