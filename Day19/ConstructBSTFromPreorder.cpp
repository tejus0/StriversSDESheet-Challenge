TreeNode<int> *construct(vector<int>& pre,int &i, int minval,int maxval,int n){
    if(i>=n) 
        return NULL;
    TreeNode<int> * root = NULL;
    int val = pre[i];
    if(val > minval && val < maxval){
        root = new TreeNode<int>(val);
        i++;
        root->left = construct(pre,i,minval,val,n);
        root->right = construct(pre,i,val,maxval,n);
    }
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0, size= preOrder.size();
    return construct(preOrder,i,INT_MIN,INT_MAX,size);
}