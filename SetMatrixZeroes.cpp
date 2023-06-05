#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    unordered_set<int> setRows;
    unordered_set<int> setColumns;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                setRows.insert(i);
                setColumns.insert(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (setRows.count(i) > 0 || setColumns.count(j) > 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}