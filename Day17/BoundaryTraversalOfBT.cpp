#include <bits/stdc++.h>
 void traverseLeft(TreeNode<int>* root,vector<int>&ans){
   if((root==NULL)||(root->left==NULL && root->right==NULL))
   return;
   ans.push_back(root->data);
   if(root->left)// if left is NOT NULL
   traverseLeft(root->left,ans);
   else
   traverseLeft(root->right,ans);
 }

  void  traverseLeaf(TreeNode<int>* root,vector<int>&ans){
      if(root==NULL)
      return ;
      if(root->left==NULL && root->right==NULL)
      {
          ans.push_back(root->data);
          return;
      }
      traverseLeaf(root->left,ans);
      traverseLeaf(root->right,ans);
 }

  void  traverseRight(TreeNode<int>* root,vector<int>&ans){
   if((root==NULL)||(root->left==NULL &&root->right==NULL))
   return;
   if(root->right)// if left is NOT NULL
   traverseRight(root->right,ans);
   else
   traverseRight(root->left,ans);
   ans.push_back(root->data);
 }

vector<int> traverseBoundary(TreeNode<int>* root){

    vector<int>ans;
    if(root==NULL)
    return ans;
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeaf(root->left,ans);//left subtree
    traverseLeaf(root->right,ans);//Right subtree
    traverseRight(root->right,ans);
    return ans;
}