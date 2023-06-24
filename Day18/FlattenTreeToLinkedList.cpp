void flatten(TreeNode<int> *root){
    if(!root)   return ;
        TreeNode<int>* tempLeft=root->left;
        TreeNode<int>* tempright= root->right;

        root->left=NULL;

        flatten(tempLeft);
        flatten(tempright);

        root->right=tempLeft;


        while(root->right!=NULL)
            root=root->right;
        
        root->right=tempright;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
  // Write your code here.
  TreeNode<int> *next = NULL;
  flatten(root);
  return root;
}