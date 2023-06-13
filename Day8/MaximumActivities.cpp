int maximumActivities(vector<int> &start, 
vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>> act(n);
    for (int i = 0; i < n; i++) {
         act.push_back({end[i],start[i]});
      }
      sort(act.begin(),act.end());
      int currtime = 1;
      int currAct=act[0].first;
      for (int i = 1; i < n; i++) {
         if (act[i].second >= currAct) {
            currtime++;
            currAct=act[i].first;
         }
      }
    return currtime;
}