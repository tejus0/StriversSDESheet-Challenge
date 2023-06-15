// Time Complexity: O(row * log(col)) .

// Space Complexity: O(1) 

int Lessthan(int mid, vector<int> &row, int len)
{
  int left = 0, high = len-1;
  while (left <= high)
  {
    int md = (left + high) >> 1;
    if (row[md] <= mid)
    {
      left = md + 1;
    }
    else
    {
      high = md - 1;
    }
  }
  return left;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=1e5;
    while(low<=high){
        int mid=low+((high-low)>>1);
        int LessNums=0;
        for (int i = 0; i < n; i++) {
            LessNums+=Lessthan(mid, matrix[i],m);
        }
        if(LessNums<=(n*m)/2)
            low=mid+1;
        else    high=mid-1;
    }
    return low;
}