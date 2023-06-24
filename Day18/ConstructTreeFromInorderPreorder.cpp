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

    TreeNode<int>* helper(vector<int>& preorder, int pS,int pE, vector<int>& inorder , int iS, int iE, map<int,int>& ind){
        if(iS>iE or pS>pE)
            return NULL;
        TreeNode<int>* node= new TreeNode<int>(preorder[pS]);

        int inInd=ind[node->data];
        int leftpart= inInd - iS;
        node->left= helper(preorder, pS+1, pS+leftpart, inorder,iS, inInd-1, ind);
        node->right = helper(preorder, pS+leftpart+1, pE, inorder,inInd+1, iE, ind);
        return node;
    }


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
  //    Write your code here
  map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode<int>* root= helper(preorder, 0 ,preorder.size()-1,inorder, 0, inorder.size()-1 , mp);
         return root;
}

