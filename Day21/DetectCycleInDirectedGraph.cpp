
bool isCyclicDAG(vector<int>* adj,vector<bool>& visited,vector<bool>& dfsVis, int j){
        visited[j]=true;
        dfsVis[j]=true;
        for(auto k : adj[j]){
            if(!visited[k] and isCyclicDAG(adj,visited,dfsVis,k)){
                return true;
            }
            else if(dfsVis[k]) return true;
        }
        dfsVis[j]=false;
        return false;
    }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<bool> visited(n+1,false),dfsVis(n+1,false);
        vector<int> adj[n+1];
        for(auto i:edges){
            adj[i.first].push_back(i.second);
        } 
        for(int i=0;i<n;i++){
          if (!visited[i]) {
            if (isCyclicDAG(adj, visited, dfsVis, i))
              return true;
          }
        }
        return false;
}