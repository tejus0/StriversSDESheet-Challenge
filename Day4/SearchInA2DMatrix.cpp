bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size(), // Initialize a variable called rows to the number of rows in the matrix.
      cols = matrix[0].size(), // Initialize a variable called cols to the number of columns in the matrix.
      row = 0, col = cols - 1; // Initialize row to 0 and col to cols minus 1.

  while (row < rows && col > -1) { // While row is less than rows and col is greater than -1.
    int cur = matrix[row][col]; // Set cur equal to the value at matrix index [row][col].
    if (cur == target) // If cur is equal to target,
      return true; // Return true.
    if (target > cur) // If target is greater than cur,
      row++; // Increment row.
    else // Otherwise,
      col--; // Decrement col.
  }

  return false; // If we reach here, then the target is not in the matrix. Return false.
}
