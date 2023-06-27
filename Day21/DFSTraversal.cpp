    vector<vector<int>> ans;

void dfs(int node, vector<int>& vis,
vector<int>* adj,vector<int>& ans){
    ans.push_back(node);
    vis[node]=1;
    for(auto& it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    } 
}

vector<vector<int>> dfsOfGraph(int V,vector<int> adj[]){

    vector<int> vis(V+1,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> comp;
            dfs(i,vis,adj,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}

vector<vector<int>> depthFirstSearch(int V, int E, 
vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for (auto &it : edges) {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfsOfGraph(V,adj);
    return ans;
}
