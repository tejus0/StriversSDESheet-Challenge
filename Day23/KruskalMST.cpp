#include <bits/stdc++.h> 
class Disjointset
{
    vector<int>rank,parent;
    public:
    Disjointset(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        
    }
    int finduparent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=finduparent(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int altu=finduparent(u);
        int altv=finduparent(v);
        if(altu==altv)
        {
            return; // no changes 
        }
        if(rank[altu]<rank[altv])
        {
            parent[altu]=altv;
        }
        else if(rank[altv]<rank[altu])
        {
            parent[altv]=altu;
        }
        else
        {
            parent[altv]=altu;
            rank[altu]+=1;
        }
    }
};

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // So for this we are gonna use Kruskal's Algorithm
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                int node=i;
                int adjnode=it[0];
                int weight = it[1];
                edges.push_back({weight,{node,adjnode}});
            }
        }
        Disjointset ds(V);
        sort(edges.begin(),edges.end());
        int sum=0; // this stores the final answer
        
        for(int i=0;i<edges.size();i++)
        {
            int node=edges[i].second.first;
            int adjnode=edges[i].second.second;
            int weight=edges[i].first;
            if(ds.finduparent(node)!=ds.finduparent(adjnode))
            {  
                sum+=weight;
               ds.unionbyrank(node,adjnode); 
            }
            
            
        }
        return sum;
        
    }
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<vector<int>> adj[n+1];
	for(int i=0;i<m;i++){
		int u=graph[i][0];
		int v=graph[i][1];
		int weight=graph[i][2];
		adj[u].push_back({v,weight});
	}
	return spanningTree(n+1,adj);
}

