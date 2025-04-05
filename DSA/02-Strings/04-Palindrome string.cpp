//Problem Link -> https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Strings&attempt_status=COMPLETED
#include <bits/stdc++.h> 
bool isvalid(char ch){ 
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
        return 1;
    }
    else return 0;
}

char tolower(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        return ch;
        else return ch-'A'+'a';
} 

bool checkPalindrome(string s)
{
    // Write your code here. 
    int length=s.size();
    int start=0; 
    int end =length-1;
    while(start<end){
        if(isvalid(s[start]) &&  isvalid(s[end]) ){
          if (tolower(s[start]) == tolower(s[end])) {
            start++;
            end--;
          }
          else return 0;
        }
        else if(isvalid(s[start])==0 &&  isvalid(s[end])==1) start++;
        else if(isvalid(s[start])==1 &&  isvalid(s[end])==0) end--;
        else{
            start++;
            end--;
        }
    }
    return 1;   
}