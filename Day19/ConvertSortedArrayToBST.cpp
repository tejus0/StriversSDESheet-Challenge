TreeNode<int>* helper(vector<int>& arr, int l, int r){
        if(l>r) return NULL;
        int mid= l+(r-l)/2;
        TreeNode<int>* newNode= 
            new TreeNode<int> (arr[mid]);
        newNode->left=helper(arr,l,mid-1);
        newNode->right=helper(arr,mid+1,r);

        return newNode;
    }

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return helper(arr,0,arr.size()-1);
}