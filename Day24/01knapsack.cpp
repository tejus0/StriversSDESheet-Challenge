#include <bits/stdc++.h>
int solve(int ind, vector<int> &values, 
vector<int> &weights,vector<vector<int>>& dp, int w){
	if(ind==values.size()-1){
		return weights[values.size()-1]<=w ? values[ind] : 0;
	}
	if(dp[ind][w]!=-1)	return dp[ind][w];
	int notTake=0+solve(ind+1,values,weights,dp,w);
	int take=INT_MIN;
	if(weights[ind]<=w){
		take=values[ind]+
		solve(ind+1,values,weights,dp,w-weights[ind]);
	}
	return dp[ind][w]=max(take,notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return solve(0,values,weights,dp,w);
}
