// Time - O(No of nodes)  , Space - O(N) for stack

//Recursive 
void inOrder(TreeNode* node, vector<int>& ans){
    if(!node)
        return ;
    inOrder(node->left,ans);
    ans.push_back(node->data);
    inOrder(node->right,ans);
}

// Iterative 
vector<int> inOrderItr(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* node=root; 
    // st.push(node->val);
    while(true){
        if(node){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node= st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inOrder(root,ans);
    return ans;
    
}
