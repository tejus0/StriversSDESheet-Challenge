// Greedy Approach 
// Time - O(N)   Space - O(1)

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> currency=
    {1000,500,100,50,20,10,5,2,1};
    int coins=0;
    int n=currency.size();
    // Write your code here
    for(int i=0;i<n;i++){
        if(amount>=currency[i]){
          while (amount) {
            amount -= currency[i];
            coins++;
          }
        }
    }
    return coins;
}




