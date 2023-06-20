// Time - O(N*LOG(N))  Space - O(K)

#include<queue>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int> ans;
	priority_queue<int> mx;
	priority_queue<int,vector<int>,greater<int>> mn;
        for(auto& it: arr){
            mn.push(it);
			mx.push(it);
            if(mn.size()>k){
                mn.pop();
            }
			if(mx.size()>k)
				mx.pop();
        }
        
		ans.push_back(mx.top());
        ans.push_back(mn.top());
	return ans;
}

