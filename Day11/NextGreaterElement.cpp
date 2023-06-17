#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &nums, int n) {
    // Write your code here
      vector < int > NGE(n, -1);
      stack < int > st;
      for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) NGE[i] = st.top();
        }
        st.push(nums[i]);
      }
      return NGE;

}