#include <bits/stdc++.h> 

vector<vector<string>> res;
bool isPalindrome(string s){
    int n=s.length();
    if(n==1)return true;
    for(int i=0;i<=n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }return true;
}
void fun(int i,string& s,vector<string>& temp){
    if(i>=s.length()){
        res.push_back(temp);
        return;
    }
    for(int k=1;k<=s.length()-i;k++){
        if(!isPalindrome(s.substr(i,k))) continue;
        temp.push_back(s.substr(i,k));
        fun(i+k,s,temp);
        temp.pop_back();   
    }
    return ;
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> temp;
        fun(0,s,temp);
        return res;
}