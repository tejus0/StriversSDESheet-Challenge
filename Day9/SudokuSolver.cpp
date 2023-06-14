

bool isvalid(int board[][9] , int row, int col, int c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}
    bool solver(int board[][9] ,int row,int col)
    {
      int j;
      int tempi=row;
       for(int i=row;i<9;i++)

       {  
        
         if(tempi==i)//this first makes a copy of orignal row passed
         {
           j=col;
         }
         else // if i changes means j has gone through 1 complete iterartion so now when we move on to the next row,we make sure we reset the col to 0;
         j=0;
          while(j<9)
           {
               if(board[i][j]==0)
               {
                   for(int z=1;z<=9;z++)
                   {
                     if (isvalid(board, i, j, z)) {
                       board[i][j] = z;

                       int tcol;
                       int trow = i;

                       tcol = (j + 1) % 9;
                       if (j == 9 - 1)
                         trow = i + 1;

                       if (solver(board, trow, tcol))
                         return true;

                       board[i][j] = 0;
                     }
                   }
                   return false;
               }
               j++;
          }
       }

       return true;
    }
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solver(matrix,0,0);
}