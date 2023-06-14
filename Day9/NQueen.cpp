
bool notAttacking(int row, int col, vector<vector<int>> &board, int n) {
  int tmpRow = row;
  int tmpCol = col;

  // checking left upper diagonal for attack for any queen
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 1)
      return false;
    row--;
    col--;
  }

  // checking left side of cols for attack from any queen
  row = tmpRow;
  col = tmpCol;
  while (col >= 0) {
    if (board[row][col] == 1)
      return false;
    col--;
  }

  // checking left downward diagonal for any attack
  row = tmpRow;
  col = tmpCol;
  while (row < n && col >= 0) {
    if (board[row][col] == 1)
      return false;
    row++;
    col--;
  }
  // if not under attack
  return true;
}

void solve(int col, vector<vector<int>> &board, 
vector<vector<int>> &res,
           int n) {
  // Base Case - if col reaches the end
  if (col == n) {
    vector<int> temp;
    for (int i = 0; i < (int)board.size(); i++) {
      for (int j = 0; j < (int)board[i].size(); j++) {
        temp.push_back(board[i][j]);
      }
    }
    res.push_back(temp);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (notAttacking(row, col, board,
                     n)) { // row is fixed and traversed in column
      board[row][col] = 1;
      solve(col + 1, board, res, n);
      board[row][col] = 0;
    }
  }
}

vector<vector<int>> solveNQueens(int n) {
  // Write your code here.
  vector<vector<int>> res;
  vector<vector<int>> board(n, vector<int>(n, 0));
  solve(0, board, res, n);
  return res;
}