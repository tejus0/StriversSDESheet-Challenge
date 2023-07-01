#include <bits/stdc++.h>
int solve(string& input1, string& input2,int n, int m, vector<vector<int>>&dp){
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (input1[n] == input2[m])
        return dp[n][m] = 1 + solve(input1, input2, n - 1, m - 1,dp);
    else
        return dp[n][m] = max(solve(input1, input2, n - 1, m,dp),solve(input1, input2, n, m - 1,dp));
    }

int lcs(string text1, string text2)
{
	//Write your code here
	 vector<vector<int>>dp(text1.size()+1,vector<int>(text2.length()+1,-1));
        return solve(text1,text2,text1.length()-1,text2.size()-1,dp);
}