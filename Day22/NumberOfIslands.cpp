#include<bits/stdc++.h>
int dir[8][2] = {{-1 , 0} , { 0 , 1} , {0 , -1} ,
 {1 , 0},{1,1},{-1,-1},{-1,1},{1,-1}};
    void bfs(int i , int j , int** grid , vector<vector<int>>&vis, int n, int m){
        vis[i][j] = 1;
        queue<pair<int,  int>>q;
        q.push({i , j});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int w = 0 ;w < 8;w++){
                int dx = a + dir[w][0];
                int dy = b + dir[w][1];
                if(dx >=0 and dx<n and dy<m and dy>= 0 and grid[dx][dy] 
                and !vis[dx][dy]){
                    vis[dx][dy] = 1;
                    q.push({dx , dy});
                }
            }
        }
    }

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
        vector<vector<int>>vis(n , vector<int>(m , 0));
        int count = 0 ;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(!vis[i][j] and arr[i][j]){
                    count++;
                    bfs( i , j , arr , vis,n,m);
                    
                }
            }
        }
        return count;
}
