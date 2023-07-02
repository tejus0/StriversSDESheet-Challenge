#include<vector>

long solve(int ind, int T, int * arr, vector<vector<long>>& dp){
  if(ind==0)  return T%arr[0]==0;
  if(dp[ind][T]!=-1) return dp[ind][T];
  long notTake = solve(ind-1,T,arr,dp);
  long take=0;
  if(arr[ind]<=T){
    take=solve(ind,T-arr[ind],arr,dp);
  }
  return dp[ind][T]=take+ notTake;
}

long countWaysToMakeChange(int *denominations, int n, int amount)
{
    //Write your code here
    vector<vector<long>>dp(n,vector<long>(amount+1,-1));
    
    return solve(n-1,amount,denominations,dp);
    // vector<long> dp(amount + 1, 0);
    //     dp[0] = 0;
        
    //     for (int i = 1; i <= amount; ++i){
    //         // for (auto & c : denominations)
    //         for (int j = 0; j < n; j++) {
    //           int c = denominations[j];
    //           if (i - c >= 0 && dp[i - c] != 0)
    //             dp[i] = dp[i] > 0 ? 
    //             min(dp[i], dp[i - c] + 1) : 
    //             dp[i - c] + 1;
    //         }
    //     }
    //     return dp[amount];
}