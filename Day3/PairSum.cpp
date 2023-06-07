#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &input, int x){
   // Write your code here.
   sort(input.begin(),input.end());   
   vector<vector<int>> ans;
   for(int i=0;i<input.size();i++)
{
    int temp=input[i];
    for(int j=i+1;j<input.size();j++)
    {
        if(temp+input[j]==x)
        {
          ans.push_back({min(temp, input[j]), max(temp, input[j])});
        }
    }
}
return ans;
}

