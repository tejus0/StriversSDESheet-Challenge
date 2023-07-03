#include <bits/stdc++.h> 

// Method 1 - Set 
// Time - O(N^2 * Log(M))

// int distinctSubstring(string &word) {
//     //  Write your code here.
//     set<string> dis;
//     int n=word.size();
//     for(int i=0;i<n;i++){
//         string s="";
//         for(int j=i;j<n;j++){
//             s+=word.substr(i,j-i+1);
//             dis.insert(s);
//         }
//     }
//     return dis.size();
// }

//Method 2 - Trie 
// Time - O(N^2)
// Space - O(N^2)

struct Node {
  Node * links[26];

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
};

int distinctSubstring(string & s) {
  Node * root = new Node();
  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    Node * node = root;
    for (int j = i; j < n; j++) {
      if (!node -> containsKey(s[j])) {
        count++;
        node -> put(s[j], new Node());
      }
      node = node -> get(s[j]);
    }
  }
  return count ;
}
