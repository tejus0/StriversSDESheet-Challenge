bool helper(BinaryTreeNode<int> * root, long long  mini, long long maxi){
        if(!root)
            return true;
        if(root->data<mini or root->data >maxi)
            return false;
        bool leftpart= helper(root->left,mini,root->data);
        bool rightpart= helper(root->right,root->data,maxi);
        //cout<<leftpart<<" "<<rightpart<<endl;
        return ( leftpart && rightpart);
    }

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return helper(root,LONG_MIN,LONG_MAX);
}