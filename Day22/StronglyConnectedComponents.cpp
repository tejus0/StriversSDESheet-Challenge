// Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.

// Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.

#include<bits/stdc++.h>
void topoSort(int node, stack<int>& st,
vector<int>& vis,vector<int> adj[]){
    vis[node]=true;
    for(auto& nbr: adj[node]){
        if(!vis[nbr]){
            topoSort(nbr, st, vis, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int>& vis,
vector<int> transpose[],vector<int>& temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto& nbr: transpose[node]){
        if(!vis[nbr]){
            revDfs(nbr, vis, transpose,temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>adj[n];
    int m=edges.size();
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);    
    }
    stack<int> st;
    vector<int> vis(n,0);

    //Step 1 - Sorting w.r.t. Finishing time .
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,st,vis,adj);
        }
    }
        // Step 2 - Reversing the graph .
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto& nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
        // Step 3 - Traversing transposed graph for different bridges .
    vector<vector<int>> ans;
  while(!st.empty()){
        int node=st.top();
        st.pop();
        vector<int> temp;
        if(!vis[node]){
            revDfs(node,vis,transpose,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}