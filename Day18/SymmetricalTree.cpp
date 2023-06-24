bool helper(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
        if (!p && !q) {
            return true;
        } else if ((!p || !q) or (p->data != q->data)) {
            return false;
        }
        
        return helper(p->left,q->right) && helper(p->right, q->left); 
    }

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(!root)   return true;
    return helper(root->left,root->right);   
}