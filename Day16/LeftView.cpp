#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int>* node, int level, 
vector<int>& ans){
    if(!node)   return;
    if(ans.size()==level)   ans.push_back(node->data);
    solve(node->left,level+1,ans);
    solve(node->right,level+1,ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    solve(root,0,ans);
    return ans;
}