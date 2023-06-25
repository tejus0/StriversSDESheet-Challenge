bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> * node=root;
        while(node){
            if(node->data==x){
                return true;
            }
            else if(node->data<x){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
        return false;
}