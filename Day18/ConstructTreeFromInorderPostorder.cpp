/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<unordered_map>
unordered_map<int,int>ump;
    TreeNode<int>* build(vector<int>& inorder, vector<int>& postorder,int &rootIdx,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        // int pivot=left;
        // while(inorder[pivot]!=postorder[rootIdx])  ->O(N) search operation eliminated by using unordered-map.
        // {
        //     pivot++;
        // }
        int pivot=ump[postorder[rootIdx]];
        rootIdx--;
        TreeNode<int>* node=new TreeNode<int>(inorder[pivot]);
        
        node->right=build(inorder,postorder,rootIdx,pivot+1,right);
        
        node->left=build(inorder,postorder,rootIdx,left,pivot-1);
        
        return node;
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, 
vector<int>& inOrder) 
{
	// Write your code here.
     int rootIdx=postOrder.size()-1;
        for(int i=0;i<inOrder.size();i++)
        {
            ump[inOrder[i]]=i;
        }
        
        return build(inOrder,postOrder, rootIdx, 0,inOrder.size()-1);
}
