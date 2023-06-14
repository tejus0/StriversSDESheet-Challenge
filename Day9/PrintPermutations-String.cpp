// Backtracking Approach 
// Time Complexity: O(N! X N)
// Space Complexity: O(1)

#include <bits/stdc++.h> 

void permutate(string nums,vector<string> &ans, int curr){
        if(curr==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=curr;i<nums.size();i++){
                swap(nums[i],nums[curr]);
                permutate(nums,ans,curr+1);
                swap(nums[i],nums[curr]);
        }
    }

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    permutate(s,ans,0);
    return ans;

}