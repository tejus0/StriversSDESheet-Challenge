#include <bits/stdc++.h> 

bool checkPal(int start,int end,string& str){
    while(start<end){
        if(str[start]!=str[end])    return false;
        start++;
        end--;
    }
    return true;
}

int solve(int ind, string& str, vector<int>& dp ){
    if(ind==str.size())  return 0;
    if(dp[ind]!=-1) return dp[ind];
    int minCost=INT_MAX;
    for(int c=ind;c<str.size();c++){
        if(checkPal(ind,c,str)){
            int cost=1+solve(c+1,str,dp);
            minCost=min(minCost,cost);
        }
    }
    return dp[ind]=minCost;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    vector<int> dp(n,-1);
    return solve(0,str,dp)-1;
}
