#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long cs=0;
    long long mxs=0;
        for(int i=0;i<n;i++){
            cs+=nums[i];
            if(cs<0) cs=0;
            mxs=max(cs,mxs);
        }
        return mxs;
}