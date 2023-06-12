// Time Complexity : O(n) +O(n log n) + O(n) 
// Space Complexity : O(N)


#include <bits/stdc++.h> 
bool static comparator(vector<int>&m1,
 vector<int>& m2){
    if (m1[1] < m2[1]) return true;
    else if (m1[1] > m2[1]) return false;
    else if (m1[2] < m2[2]) return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start,
 vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<vector<int>> meet;
    for (int i = 0; i < n; i++) {
         meet.push_back({start[i],end[i],i+1});
      }
      sort(meet.begin(),meet.end(), comparator);
      vector < int > answer;
      int limit = meet[0][1];
      answer.push_back(meet[0][2]);
      for (int i = 1; i < n; i++) {
         if (meet[i][0] > limit) {
            limit = meet[i][1];
            answer.push_back(meet[i][2]);
         }
      }
    return answer;
}