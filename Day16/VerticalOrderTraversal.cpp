#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;  // vector<int> ans only for gfg
        if(!root) return ans;
        
        map<int,map<int,vector<int>>> nodes;
        queue<pair<TreeNode<int>* , pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            TreeNode<int> *n  = it.first;
            int idx = it.second.first, lvl = it.second.second;
            
            nodes[idx][lvl].push_back(n->data);
            
            if(n->left) q.push({n->left,{idx-1,lvl+1}});
            if(n->right) q.push({n->right,{idx+1,lvl+1}});
        }
        for(auto idx : nodes)
        {
            for(auto lvl:idx.second)
            {                
                for(int it : lvl.second)
                {
                    ans.push_back(it);
 
                }
            }
        }
        
        return ans;
}