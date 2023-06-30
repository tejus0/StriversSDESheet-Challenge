int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    // Method 1 - Floyd Warshall
    vector<int> distance(n+1, 1e9);
    distance[src] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] != 1e9 && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    return distance[dest];

    //Method 2- Bellman Ford working fine .
    // vector<int> dist(n+1, 1e9);
    // dist[src] = 0;
    // for (int i = 0; i <n-1; i++){
    //     for(auto& it: edges){
    //         int start=it[0];
    //         int finish=it[1];
    //         int edgeWt=it[2];
    //         if(dist[start]!=dist[finish])
    //         dist[finish]=min(dist[start]+edgeWt,dist[finish]);
    //     }
    // }
    // for (auto it : edges) {
	// 		int u = it[0];
	// 		int v = it[1];
	// 		int wt = it[2];
	// 		if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
	// 			return { -1};
	// 		}
	// 	}


	// 	// return dist;
    // return dist[dest];
}


