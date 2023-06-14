#include <bits/stdc++.h>

void dfs(int x, int y, const vector<vector<int>> &maze, int n,
         vector<vector<int>> &ans, vector<vector<int>> moves,
         vector<vector<bool>> visited) {
  if (x >= n || y >= n || x < 0 || y < 0)
    return;
  if (visited[x][y])
    return;
  if (maze[x][y] == 0) {
    visited[x][y] = true;
    return;
  }
  if (x == n - 1 && y == n - 1) {
    moves.push_back({x, y});
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (vector<int> v : moves) {
      grid[v[0]][v[1]] = 1;
    }
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
        temp.push_back(grid[i][j]);
      }
    }
    ans.push_back(temp);
    return;
  }
  moves.push_back({x, y});
  visited[x][y] = true;
  int dx[] = {-1, 0, 0, 1};
  int dy[] = {0, -1, 1, 0};
  for (int d = 0; d < 4; d++) {
    int px = x + dx[d], py = y + dy[d];
    dfs(px, py, maze, n, ans, moves, visited);
  }
  return;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n) {
  vector<vector<int>> ans;
  vector<vector<int>> moves;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  dfs(0, 0, maze, n, ans, moves, visited);
  return ans;
}