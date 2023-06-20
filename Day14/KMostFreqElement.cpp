

#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, 
vector<int> &nums)
{
    // Write your code here.
    vector<int>ans;
        map<int,int>mp;
        for(auto& it: nums)
            mp[it]++;
        multimap<int,int>mm;
        for(auto& it:mp)
            mm.insert({it.second,it.first});
        for(auto it=mm.rbegin();it!=mm.rend();it++){
            if(k==0)
                break;
            ans.push_back(it->second);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
}