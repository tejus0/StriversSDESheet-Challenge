int ans=0,curr_sum=0;
  map<int,int> mp;
  int n=arr.size();
  for(int i=0;i<n;i++){
    curr_sum+=arr[i];
    if(curr_sum==0){
      ans=i+1;
    }
    else{
      if(mp.find(curr_sum)!=mp.end()){
        ans=max(ans,i-mp[curr_sum]);
      }
      else{
        mp.insert({curr_sum,i});
      }
    }
  }
  return ans;