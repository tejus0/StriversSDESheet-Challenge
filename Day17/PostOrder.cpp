// Time Complexity: O(N).
// Space Complexity: O(N)

void solve(vector<int>& post,TreeNode* root){
        if(root==NULL)  return;
        solve(post,root->left);
        solve(post,root->right);
        post.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        
        return post;

    }

// Time Complexity: O(N).
// Space Complexity: O(N+N)

vector < int > postOrderTrav(node * curr) {

  vector < int > postOrder;
  if (curr == NULL) return postOrder;

  stack < node * > s1;
  stack < node * > s2;
  s1.push(curr);
  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr -> left != NULL)
      s1.push(curr -> left);
    if (curr -> right != NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
  }
  return postOrder;
}

// Time Complexity: O(N).
// Space Complexity: O(N)

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector < int > postOrder;
    TreeNode* cur=root;
  if (cur == NULL) return postOrder;

  stack < TreeNode* > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      TreeNode* temp = st.top() -> right;
      if (temp == NULL) {
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}
