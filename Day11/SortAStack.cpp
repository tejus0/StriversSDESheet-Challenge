#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	// Write your code here
	vector<int> v;
	while(!stack.empty()){
		int y=stack.top();
		stack.pop();
		v.push_back(y);
	}
	sort(v.begin(),v.end());
	for(auto& it: v){
		stack.push(it);
	}
}