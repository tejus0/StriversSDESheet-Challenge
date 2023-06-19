// Time - O(N*M)   Space - O(1)

string longestCommonPrefix(vector<string> &arr, int n)
{
  string ans="";
  for(int i=0;i<arr[0].size();i++){
      for(int j=0;j<arr.size();j++){
          if(arr[0][i]!=arr[j][i]){
              return ans;
          }
      }
      ans.push_back(arr[0][i]);
  }
  return ans;
}

// Time - O(n* Log(N))
// Space - O(1)

#include<bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n==0)return "";
	if(n==1)return arr[0];
	sort(arr.begin(),arr.end());
	string ans="";
	string a=arr[0];
	string b=arr[n-1];
	for(int i=0;i<a.size();++i){
		if(a[i]!=b[i])
            break;
		ans.push_back(a[i]);
	}
	return ans;
}


