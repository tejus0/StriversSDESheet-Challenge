#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int ans=0,curr_xor=0;
  map<int,int> mp;
  int n=arr.size();
  for(int i=0;i<n;i++){
    curr_xor^=arr[i];
    if(curr_xor==x){
      ans++;
    }
    if(mp.find(x^curr_xor)!=mp.end()){
        ans += mp[x^curr_xor];
    }
    mp[curr_xor]++;
  }
  return ans;
}