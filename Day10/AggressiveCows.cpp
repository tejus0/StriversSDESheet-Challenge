// Time Complexity: O(N*log(M))
// Space Complexity : O(1)

bool isPossible(vector<int> &a, int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows)
        return true;
      return false;
}
int aggressiveCows(vector<int> &stalls, int cows)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
      int low = 0, high = stalls[n - 1] - stalls[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(stalls, n, cows, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return high;
}