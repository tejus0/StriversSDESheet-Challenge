// Brute Force Approach : use of set data structure 
// Time Complexity - O(N* logN) + O(N)
// Space Complexity - O(N)

#include<bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n) {
	set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

Optimal Approach - 2 Pointer .
Time Complexity : O(N)
Space Complexity : O(1)

#include<bits/stdc++.h>

int removeDuplicates(vector<int> &nums, int n) {
	// Write your code here.
	int i=0,j=1;
        while(j<n){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
            else{
                j++;
            }
        }
	return i+1;

}
