
int f(int ind , int remLen ,vector<int>& price,vector<vector<int>>& dp ){
        
        if(ind==0) return remLen* price[0];
        if(dp[ind][remLen]!=-1)    return dp[ind][remLen];
        int notTake=0+f(ind-1,remLen,price,dp);
        int take=INT_MIN;
		int rodLen=ind+1;
		if(rodLen<=remLen){
			take=price[ind]+f(ind,remLen-rodLen,price,dp);
		}
		return dp[ind][remLen]=max(take,notTake);
    }
    

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1 , n , price,dp);
}
