int longestSubSeg(vector<int> &nums , int n, int k){
    // Write your code here.
        int count=0;
        int ans=0;
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0 ){
                count++;
            }
            while(count>k){
                j++;
                if(nums[j]==0){
                    count--;
                }
            }
            int len=i-j;
            ans=max(ans,len);
        }
        return ans;
}

