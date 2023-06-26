/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
 string s="";
        if(!root)
            return s;
        queue<TreeNode<int>*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode<int>* curr=que.front();
            que.pop();
            if(!curr){
                s+="#,";
            }
            else{
                s+=(to_string(curr->data)+",");
            }
            if(curr){
                    que.push(curr->left);
                    que.push(curr->right);
            }
        }
        // cout<<s;
        return s;

}

TreeNode<int>* deserializeTree(string &data)
{
 //    Write your code here for deserializing the tree
        if(data.size()==0)
            return NULL;
        stringstream obj(data);
        string str;
        getline(obj,str,',');
        TreeNode<int>* root= new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode<int>* curr= que.front();
            que.pop();
            getline(obj,str,',');
            if(str=="#"){
                curr->left=NULL;
            }
            else{
                TreeNode<int>* leftNode= new TreeNode<int>(stoi(str));
                curr->left=leftNode;
                que.push(leftNode);
            }
            getline(obj,str,',');
            if(str=="#"){
                curr->right==NULL;
            }
            else{
                TreeNode<int>* rightNode= new TreeNode<int>(stoi(str));
                curr->right=rightNode;
                que.push(rightNode);
            }
        }
        return root;
}



