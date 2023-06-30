#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, 
int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices];
    for(auto& it: vec){
        int Snode=it[0];
        int Enode=it[1];
        int weigh=it[2];
        adj[Snode].push_back({Enode,weigh});
        adj[Enode].push_back({Snode,weigh});
    }
    priority_queue<pair<int , int> ,vector<pair<int , int>>,
     greater<pair<int , int>> > pq;
    vector<int> dis(vertices,INT_MAX);
    dis[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        int node=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(auto& it: adj[node]){
            int edgeWeight=it.second;
            int nbrNode=it.first;
            if(dist+edgeWeight<dis[nbrNode]){
                dis[nbrNode]=dist+edgeWeight;
                pq.push({dis[nbrNode],nbrNode});
            }
        }
    }
    return dis;

}
