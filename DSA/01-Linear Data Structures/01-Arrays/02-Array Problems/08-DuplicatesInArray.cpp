//Problem Link -> https://www.naukri.com/code360/problems/duplicate-in-array_893397?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED

int findDuplicate(vector<int> &arr) 
{
    // Write your code here 
    int ans=0; 
    for(int i=0; i<arr.size();i++) {
        ans = ans ^ arr[i];
    } 
    for(int i=1; i<arr.size(); i++) {
        ans = ans ^ i;
    } 
    return ans;
    
	
}

//Partially Accpeted solution with TLE at one test-case -> 
/*
int findDuplicate(vector<int> &arr) 
{
    // Write your code here 
    for(int i=0; i<arr.size(); i++) { 
        for(int j=i+1; j<arr.size(); j++) {
            if((arr[i]==arr[j]) && (i!=j)) {
                return arr[i];
            } 
        }
    } 
    return -1;
	
}
*/
