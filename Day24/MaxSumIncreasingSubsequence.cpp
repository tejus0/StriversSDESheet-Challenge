#include <bits/stdc++.h> 

int solve(int ind,int prev, vector<int> &rack, 
vector<vector<int>>& dp){
	if(ind==rack.size()){
		return 0;
	}
	if(dp[ind][prev+1]!=-1)	return dp[ind][prev+1];
	int notTake=0+solve(ind+1,prev,rack,dp);
	int take=INT_MIN;
	if(prev == -1 || rack[prev]<rack[ind]){
		take=rack[ind]+ solve(ind+1,ind,rack,dp);
	}
	return dp[ind][prev+1]=max(take,notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return solve(0,-1,rack,dp);
}