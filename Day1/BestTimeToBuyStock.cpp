#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int buy=prices[0];
        int profit=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int sell=prices[i];
            buy=min(buy,sell);
            profit=max(profit,sell-buy);
        }
        return profit;
}