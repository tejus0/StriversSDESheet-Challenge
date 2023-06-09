#include <bits/stdc++.h> // Include all standard libraries to reduce lines of code.

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0; // Initialize a variable called top to 0.
    int down=n-1; // Initialize a variable called down to n minus 1.
    int left=0; // Initialize a variable called left to 0.
    int right=m-1; // Initialize a variable called right to m minus 1.
    int d=0; // Initialize a variable called d to 0.
    int temp; // Initialize a variable called temp.

    while(top<down && left<right){ // While the top is less than down and left is less than right.
        temp = mat[top][left]; // Set temp equal to the value at matrix index [top][left].
        for(int i=left+1;i<=right;i++){ // For loop to swap values moving from left to right.
            swap(temp,mat[top][i]); // Swap the value of temp with the value at the current matrix index.
        }
        top++; // Increment the value of top.

        for(int i=top;i<=down;i++){ // For loop to swap values moving from top to down.
            swap(temp,mat[i][right]); // Swap the value of temp with the value at the current matrix index.
        }
        right--; // Decrement the value of right.

        for(int i=right;i>=left;i--){ // For loop to swap values moving from right to left.
            swap(temp,mat[down][i]); // Swap the value of temp with the value at the current matrix index.
        }
        down--; // Decrement the value of down.

        for(int i=down;i>=top;i--){ // For loop to swap values moving from down to top.
            swap(temp,mat[i][left]); // Swap the value of temp with the value at the current matrix index.
        }
        left++; // Increment the value of left.

        mat[top-1][left-1] = temp; // Set the value of matrix index [top-1][left-1] equal to temp.
    }
}
