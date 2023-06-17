// Brute Force Approach 
// Time - O(N^K)   Space - O(1) ignoring the no of windows vector .

#include <bits/stdc++.h> 

void GetMax(vector < int > nums, int l, int r, vector < int > & arr) {
  int i, maxi = INT_MIN;
  for (i = l; i <= r; i++)
    maxi = max(maxi, nums[i]);
  arr.push_back(maxi);
}

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int left = 0, right = 0;
  int i, j;
  vector < int > arr;
  while (right < k - 1) {
    right++;
  }
  while (right < nums.size()) {
    GetMax(nums, left, right, arr);
    left++;
    right++;
  }
  return arr;

}


// Similar Approach - Priority queue 
// Time - O(N* Log(K))   Space - O(K)

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &arr, int &k)
{
    int n = arr.size();
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < k; i++){
        pq.push({arr[i], i});
    }

    ans.push_back(pq.top().first);

    for(int i = k; i < n; i++){
        pq.push({arr[i], i});
        if(pq.top().second <= i-k){
            while(pq.top().second <= i-k){
                pq.pop();
            }
        }
        ans.push_back(pq.top().first);
    }

    return ans;
}

// Best Approach - Deque . Similar to NGR .
// Time - O(N)  Space - O(K)

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) 
        dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}