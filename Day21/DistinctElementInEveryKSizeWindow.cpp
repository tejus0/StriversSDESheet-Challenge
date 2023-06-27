#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    unordered_map<int, int> map;
    vector<int> ans;
  // Handling the 1st K elements
  for (int i = 0; i < k; i++)
    map[arr[i]] = map[arr[i]] + 1;

    ans.push_back(map.size());
//   cout << map.size() << " ";
  for (int i = k; i < arr.size(); i++) {
    // removing the (i-k)th element
    if (map[arr[i - k]] == 1)
      map.erase(arr[i - k]);
    else
      map[arr[i - k]] = map[arr[i - k]] - 1;
    // Adding the nxt value in map
    map[arr[i]] = map[arr[i]] + 1;
    ans.push_back(map.size());
    // cout << map.size() << " ";
  }
//   cout << endl;

	return ans;
}
