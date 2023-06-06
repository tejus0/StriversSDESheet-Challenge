#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        vector<int> curr=intervals[0];
        for(auto& it: intervals){
            if(it[0]<=curr[1]){
                curr[1]=max(it[1],curr[1]);
                
            }
            else{
                answer.push_back(curr);
                curr=it;
            }
        }
        answer.push_back(curr);
        return answer;
}
