// Time - O(N * Log (N))
// Space - O(1)

#include <bits/stdc++.h> 

int isPossible(vector < int > & A, 
long long int pages, int students) {
  int cnt = 1;
  long long int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] <= pages) {
      sumAllocated += A[i];
    } else {
      cnt++;
      if (cnt > students || A[i]>pages) return false;
      else sumAllocated = A[i];
    }
  }
  if (cnt < students) return true;
  return true;
}

long long int ayushGivesNinjatest(int n, int m, 
vector<int>& time) 
{
	// Write your code here.
	if (n > m) return -1;
  long long int low = 0;
  long long int high = 0;
  long long int ans= -1;
  //to find minimum value and sum of all pages
  for (int i = 0; i < m; i++) {
    high = high + time[i];
  }
  //binary search
  while (low <= high) {
    long long int mid = low+((high-low) >> 1);
    if (isPossible(time, mid, n)) {
		ans=mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}


