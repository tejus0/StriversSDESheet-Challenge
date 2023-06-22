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

void rec(TreeNode* node,vector<int>& ans){
    if(!node)   return ;
    ans.push_back(node->data);
    rec(node->left,ans);
    rec(node->right,ans);
}

vector<int> preorderItr(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            result.push_back(root->data);
            if(root->right) st.push(root->right);
            if(root->left)  st.push(root->left);

        }
    return result;
    }

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans = preorderItr(root);
    // rec(root,ans);
    return ans;
}