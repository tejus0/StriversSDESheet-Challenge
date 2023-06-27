#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(!node) return node;
        unordered_map<graphNode *,graphNode *> m;
        graphNode * ans = new graphNode(node->data);
        m[node]=ans;
        queue<graphNode *> q;
        q.push(node);
        while(!q.empty()){
            graphNode * currNode=q.front();
            q.pop();
            vector<graphNode *> neigh = 
			currNode->neighbours;
            for(auto x:neigh){
                if(m.find(x)==m.end()){
                    m[x] = new graphNode(x->data,{});
                    q.push(x);
                }
                m[currNode]->neighbours.push_back(m[x]);
            }
        }
        return ans;
}