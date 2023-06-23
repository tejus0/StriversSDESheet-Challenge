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

int height(BinaryTreeNode<int>* node){
        if(!node)
            return 0;
        int hl=height(node->left);
        int hr=height(node->right);
        if(hl==-1 || hr==-1)
            return -1;
        if(abs(hl-hr)>1){
            return -1;
        }
        return max(hl,hr)+1;
    }

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(height(root)!=-1)    return true;
    return false;
}