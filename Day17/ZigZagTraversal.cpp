#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
        queue<BinaryTreeNode<int> *> que;
        if(root==NULL){
            return ans;
        }
        bool flag=true;
        que.push(root);
        while(que.size()){
            int sz=que.size();
            vector<int> level(sz);
             for (int i = 0; i < sz; i++) {
                BinaryTreeNode<int> * node = que.front();
                que.pop();
                int idx= flag ? i: (sz-i-1);
                level[idx]=node->data;
                if(node->left!=NULL)
                    que.push(node->left);
                if (node->right!=NULL)
                    que.push(node->right);
            }
                ans.insert(ans.end(),level.begin(),
                level.end());
            flag=!flag;
        }
        return ans;
}
