// Problem Link -> https://www.naukri.com/code360/guided-paths/data-structures-algorithms-new/content/662513/offering/10676520?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
int linearSearch(vector<int> &a, int x) {
    //    Write your code here
    for(int i=0; i<=a.size(); i++) {
        if(a[i]==x) {
            return i;
        }
    } 
    return -1;
}