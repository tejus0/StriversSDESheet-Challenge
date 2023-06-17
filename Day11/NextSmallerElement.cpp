#include<stack>

vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // Write your code here.
    vector < int > NSE(n, -1);
      stack < int > st;
      for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums[i]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) NSE[i] = st.top();
        }
        st.push(nums[i]);
      }
      return NSE;
}
