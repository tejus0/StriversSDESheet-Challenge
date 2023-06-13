// Recursive Approach 
// Time - O(2^n)+O(2^n log(2^n))   Space - O(2^N)

#include <bits/stdc++.h> 

void solve(int ind, int sum,vector<int>& num, int n, vector<int>& ans){
    if(ind==n) {
        ans.push_back(sum);
        return ;
    }
    solve(ind+1,sum+num[ind],num,n,ans);
    solve(ind+1,sum,num,n,ans);

}


vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n=num.size();
    solve(0,0,num,n,ans);
    sort(ans.begin(),ans.end());
    return ans;
}