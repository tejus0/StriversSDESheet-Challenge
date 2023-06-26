int inorder(TreeNode<int>* root, int& k, int& res) {  //Time - O(N)   Space - O(N)
        if (!root) return -1;
        int Rele=inorder(root->right, k,res);
        if(Rele!=-1)    return Rele;
        if (--k == 0) res = root->data;
        return inorder(root->left, k,res);
    }

void inorderhelp(TreeNode<int>* root,vector<int>& x){     //Time - O(N)   Space - O(N + N)
    if(root==NULL){
        return;
    }
    inorderhelp(root->left,x);
    x.push_back(root->data);
    inorderhelp(root->right,x);
    //inorder traversal
}

 
int KthLargestNumber(TreeNode<int>* root, int k)    //Time - O(N)   Space - O(1)
{
    // Write your code here.
    int ans=-1;
    // vector<int> arr;
    // inorderhelp(root, arr);
    // int n=arr.size();
    // if(k>n) return -1;
    // // return arr[n-k];
    // k=n-k+1;
     inorder(root,k,ans);
     return ans;
}
