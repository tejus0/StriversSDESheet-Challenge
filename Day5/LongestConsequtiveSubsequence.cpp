#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longest=1;
    int smaller=INT_MIN, count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]-1==smaller){
            count++;
        }
        else if(arr[i]!=smaller){
            count=1;
        }
        smaller=arr[i];
        longest=max(longest,count);
    }
    return longest;
}