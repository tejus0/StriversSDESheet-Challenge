#include <bits/stdc++.h> 

//DFS traversal
void findTopo(int node, vector<int>& vis, stack<int>& st,vector<int> adj[]){
    vis[node]=1;
    for(auto& it: adj[node]){
        if(!vis[it]){
            findTopo(it,vis,st,adj);
        }
    }
        st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            findTopo(i,vis,st,adj);
        }

    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

//BFS Traversal
vector<int> KhanAlgoTopo(int n, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto& it: adj[i])   indegree[it]++;
    }
    for(int i=0;i<n;i++){
        if(!indegree[i]) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto& it: adj[node]){
            indegree[it]--;
            if(!indegree[it])   q.push(it);
        }
    }
    return topo;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    for(auto& it: edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }
    // vector<int> ans=topoSort(v,adj);
    vector<int> ans=KhanAlgoTopo(v,adj);
    return ans;
}