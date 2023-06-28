#include<bits/stdc++.h>
bool bfs(int src,  vector<int> adj[],vector<int>& color){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& neigh: adj[node]){
                if(color[neigh]==-1){
                    q.push(neigh);
                    color[neigh]=1-color[node];
                }
                else if(color[neigh]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int v=edges.size();
	vector<int> adj[v];
    for(int i=0;i<v;i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]){
				adj[i].push_back(j);
                adj[j].push_back(i);
			}
		}
	}
        vector<int> color(v,-1);
	    for(int i=0;i<v;i++){
	        if(color[i]==-1){
    	        if(!bfs(i,adj,color)){
    	            return false;
    	        }
    	    }
	    }
	    return true;
}