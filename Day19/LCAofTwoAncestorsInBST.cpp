TreeNode<int>* LCAinaBST(TreeNode<int>* node, 
    TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    if(node==NULL)
            return NULL;
        if(node->data>p->data and q->data<node->data)
            return LCAinaBST(node->left,p,q);
        if(node->data<p->data and q->data>node->data)
            return LCAinaBST(node->right,p,q);
        return node;
}
