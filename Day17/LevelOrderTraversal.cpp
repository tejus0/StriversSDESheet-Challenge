#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int>*> q;
        vector<int> lo;
        if(!root){
            return lo;
        }
        q.push(root);
        while(!q.empty()){
            int levelSz=q.size();
            // vector<int> level;
            while(levelSz--){
                BinaryTreeNode<int>* node=q.front();
                q.pop();
                lo.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            // lo.push_back(level);
        }
        return lo;
}