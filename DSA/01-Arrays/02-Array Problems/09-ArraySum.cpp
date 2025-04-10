//Problem Link -> https://www.naukri.com/code360/guided-paths/data-structures-algorithms-new/content/662498/offering/10674890?leftPanelTabValue=PROBLEM
int arraySum(int arr[], int n)
{ 
    int sum=0;
    for(int i=0; i<=n-1; i++) {
        sum = sum + arr[i];
    } 
    return sum;

}
