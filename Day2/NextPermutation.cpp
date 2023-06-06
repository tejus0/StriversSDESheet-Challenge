#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> 
&nums, int n)
{
    //  Write your code here.
    int peak=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                peak=i;
                break;
            }
        }
        if(peak==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int swappy=peak;
            for(int i=peak+1;i<n;i++){
                //cout<<swappy<<" ";
                if(nums[peak-1]<nums[i] and nums[i]<=nums[swappy]){
                    swappy=i;
                    //cout<<swappy<<" ";
                }
            }
            //cout<<nums[peak-1]<<" ";
            swap(nums[peak-1],nums[swappy]);
            reverse(nums.begin()+peak,nums.end());
        }
    return nums;
}