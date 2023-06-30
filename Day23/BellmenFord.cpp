#include <bits/stdc++.h> 

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    for (int i = 0; i <n-1; i++){
        for(auto& it: edges){
            int start=it[0];
            int finish=it[1];
            int edgeWt=it[2];
            if(dist[start]!=dist[finish])
            dist[finish]=min(dist[start]+edgeWt,dist[finish]);
        }
    }
    for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		// return dist;
    return dist[dest];
}