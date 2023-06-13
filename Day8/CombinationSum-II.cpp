#include<bits/stdc++.h>
void rec(int tgt,vector<int>& arr,int ind,
vector<vector<int>>& ans,vector<int>& temp){
  if(ind==arr.size()){
    if (tgt == 0) {
      ans.push_back(temp);
    }
    return;
  }
  if(arr[ind]<=tgt){
        temp.push_back(arr[ind]);
        rec(tgt-arr[ind],arr,ind+1,ans,temp);
        temp.pop_back();
    }
    while(ind+1<arr.size() && arr[ind]==arr[ind+1]) 
	ind++;
    rec(tgt,arr,ind+1,ans,temp);
    }

vector<vector<int>> combinationSum2(vector<int> &arr,
 int n, int target)
{
	// Write your code here.
	vector<vector<int>> ans;
        vector<int> temp;
		sort(arr.begin(),arr.end());
        rec(target,arr,0,ans,temp);
        return ans;
}
