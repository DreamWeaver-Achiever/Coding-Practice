//Problem Link -. https://www.naukri.com/code360/problems/string-reverse_3210207?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Strings&attempt_status=COMPLETED

#include <bits/stdc++.h> 
int lengthOfTheString(string str) {
     int countWords=0; 
    for(int i=0; str[i]!='\0'; i++) {
        countWords ++;
    } 
    int countSpace=0; 
    for(int i=0; str[i]!='\0'; i++) { 
        if(str[i]==' ') { 
            countSpace++; 
        } 
    }
    int actualLength=countWords-countSpace;
    return actualLength;
}
string stringReverse(string S) {
    // Write your code here. 
    int start =0; 
    int end = lengthOfTheString(S)-1; 
    while(start<end) {
        swap(S[start], S[end]); 
        start++; 
        end--;
    } 
    return S;
  
}