#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &nums, 
int target){
   // Write your code here.
   int n=nums.size();
   vector<vector<int>> ans;
   unordered_map<int, int> myMap;
   for (int i = 0; i < nums.size(); i++) {
      int count=myMap[target-nums[i]];
      vector<int>p(2);
      p[0]=nums[i];
      p[1]=target-nums[i];
      while(count--){
         ans.push_back(p);
      }
      myMap[nums[i]]++;
   }
   for(int i=0;i<ans.size();i++){
      vector<int> pair=ans[i];
      if(pair[0]>pair[1]){
         swap(pair[0],pair[1]);
      }
      ans[i]=pair;
   }
   sort(ans.begin(),ans.end());
   return ans;
}



