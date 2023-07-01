#include <bits/stdc++.h> 

int solve(int m, int n,vector<vector<int>>& dp,vector<vector<int>> &nums){
        if(m==0 and n==0)
            return nums[m][n];
        if(m<0 || n<0)
            return 1e9;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int up=solve(m-1,n,dp,nums);
        int left=solve(m,n-1,dp,nums);
        dp[m][n]=min(left,up)+nums[m][n];
        return dp[m][n];
    }

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
}