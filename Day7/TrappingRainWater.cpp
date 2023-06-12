// Brute Force Approach - Time Complexity = O ( N ^ 2 )
                        // - Space Complexity = O ( 1 )

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
  long waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    long leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

// Better Approach - Prefix Array and Suffix Array
// Time Complexity = O ( N * 3 )
// Space Complexity = O(N) + O(N)

int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}


// Best Approach : left max and right max pointers .
// Time Complexity : O(N)
// Space Complexity : O(1).

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
  long lmax=0, rmax=0;
  int l=0, r=n-1;
  long ans=0;
  while(l<r){
      lmax=max(lmax,arr[l]);
      rmax=max(rmax,arr[r]);
      if(lmax<rmax){
          ans+=lmax-arr[l];
          l++;
      }
      else{
          ans+=rmax-arr[r];
          r--;
      }
  }
  return ans;
}