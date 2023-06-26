void inorder(TreeNode<int>* root, int& k, int& res) {
        if (!root) return;
        inorder(root->left, k,res);
        if (--k == 0) res = root->data;
        inorder(root->right, k,res);
    }
    
int inorderMorris(TreeNode<int> *root, int k)
{
    int cnt=0,ans=-1;
    TreeNode<int>* curr;
    while(curr){
        if(!curr->left){
            cnt++;
            if(cnt==k)  return curr->data;
            curr=curr->right;
        }
        else{
            TreeNode<int>* leftSub=curr->left;
            while(leftSub->right and leftSub->right!=curr){
                leftSub=leftSub->right;
            }
            if(!leftSub->right){
                leftSub->right=curr;
                curr=curr->left;
            } else {
              leftSub->right = NULL;
              cnt++;
              if (cnt == k)
                return curr->data;
              curr = curr->right;
            }
        }
    }
    return ans;
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    return inorderMorris(root, k);
    // int res;
    // inorder(root, k,res);
    // return res;
}