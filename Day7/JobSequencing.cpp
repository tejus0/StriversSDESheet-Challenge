// Time : O(N log N) + O(N*M).
// Space : O(M).
// where M is the maximum deadline. and N is jobs .


#include <bits/stdc++.h> 


bool static comparison(vector<int>& j1, vector<int>& j2 ){
    return (j1[1]>j2[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), comparison);
      int maxi = jobs[0][0];
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, jobs[i][0]);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = jobs[i][0]; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               jobProfit += jobs[i][1];
               break;
            }
         }
      }

      return jobProfit;
}
