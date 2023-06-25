
int findCeil(BinaryTreeNode<int> *root, int X){
    // Write your code here.
    int ceil=-1;
    while(root){
        if(root->data==X){
            ceil=root->data;
            return ceil;
        }
        if (X < root->data) {
          ceil = root->data;
          root = root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;

}