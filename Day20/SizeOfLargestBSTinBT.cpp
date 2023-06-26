vector<int> largestBSTSubtreeHelper(TreeNode<int>* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }
        
        // Get dataues from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left[1] < root->data && root->data < right[0]) {
            // It is a BST.
            return {min(root->data, left[0]), max(root->data, right[1]), 
                            left[2] + right[2] + 1};
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be dataid BST
        return {INT_MIN, INT_MAX, max(left[2], right[2])};
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    vector<int> ans= largestBSTSubtreeHelper(root);
    return ans[2];
}
