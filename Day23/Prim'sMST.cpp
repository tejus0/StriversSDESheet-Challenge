//  Method 1 - Code using Priority queue :  

// #include <bits/stdc++.h> 
// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
//  vector<pair<pair<int, int>, int>> &g)
// {
//     // create adjacency list
//     unordered_map<int, vector<pair<int, int>>> adj;
//     for(auto i : g) {
//         int u = i.first.first;
//         int v = i.first.second;
//         int w = i.second;

//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }

// 		// min heap to get node with minimum weight
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
// 	  // let source as 1, and inititally distance of source is 0
// 		// {weight, node}  
// 		pq.push({0, 1});

//     vector<int> key(n+1, INT_MAX), parent(n+1, -1), visited(n+1, 0);

//     parent[1] = -1;
// 		// weight to reach i is key[i]
//     key[1] = 0;

//     while(pq.size()) {
//         int w = pq.top().first;
//         int node = pq.top().second;
//         visited[node] = 1;
//         pq.pop();

// 				// find node with minimum weight and to to its neighbour 
//         for(auto nbr: adj[node]) {
//             int toGo = nbr.first;
//             int toGoWeg = nbr.second;

// 						// if to react node N from key[N] update weight(key[N]) with distance from node to N
//             if(visited[toGo] == 0 && toGoWeg < key[toGo]) {

//                 key[toGo] = toGoWeg;
//                 parent[toGo] = node;
//                 pq.push({toGoWeg, toGo});  //not marking nbr as visited because it is not final minimum weight .
//             }
//         }

//     }

//     vector<pair<pair<int, int>, int>> ans;
// 	   // loop from 2 because parent of 1 is -1 (1 is initial node)
// 		for(int i = 2; i <= n; i++) {
//         ans.push_back({{parent[i], i}, key[i]});

//     }
    
//     return ans;
// }


//  Method 2 - Using parent and key for finding min of all .

#include <bits/stdc++.h> 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // create adj list
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    //let start the algo with 1 as root node .
    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++){  // For getting n-1 edges of MST .
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){  // Getting minimum edge of all .
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }

       // mark min node as true;
        mst[u]=true;
        //updating if adj nodes get lesser weight . 
        for(auto it:adj[u]){
            int nbr=it.first;
            int weigh=it.second;
            if(!mst[nbr] && weigh<key[nbr]){  
                parent[nbr]=u;
                key[nbr]=weigh;
            }
        }
    }

    vector<pair<pair<int, int>, int>>result;
    for(int i=2;i<=n;i++){
      result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}