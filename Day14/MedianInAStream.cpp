// Time - O(N* LOG(N))  Space - O(N)

#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	// if(n==0)    return ;
	vector<int> ans;
    priority_queue<int> mx;  
    priority_queue<int, vector<int>, greater<int>> mn;
    for(int i=0; i<n; i++){
        int x=arr[i];
        if (mx.size() == 0) {
          mx.push(x);
		  ans.push_back(mx.top());
        } else if (mx.size() > mn.size()) {
          if (x < mx.top()) {
            mn.push(mx.top());
            mx.pop();
            mx.push(x);
          } else {
            mn.push(x);
          }
          ans.push_back((mx.top() + mn.top()) / 2);
          // cout << (mx.top() + mn.top())/2 << " ";
        } else {
          if (x < mx.top())
            mx.push(x);
          else {
            mn.push(x);
            mx.push(mn.top());
            mn.pop();
          }
          ans.push_back(mx.top());
          // cout<< mx.top()<<" ";
        }
        // if(mx.size() == mn.size())
        //     cout << (mx.top() + mn.top())/2 << " ";
        // else cout << mx.top() << " ";  
    }
	return ans;
}
