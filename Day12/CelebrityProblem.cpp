#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int>stk;
	for(int i=0;i<n;i++) {
		stk.push(i);
	}
	while(stk.size()>1) {
		int p1=stk.top();
		stk.pop();
		int p2=stk.top();
		stk.pop();
		if(knows(p1,p2)) {
			stk.push(p2);
		}
		else {
			stk.push(p1);
		}
	}
	int p=stk.top(),count=0;
	stk.pop();
	for(int i=0;i<n;i++) {
		if(knows(p,i)) {
			return -1;
		}
		if(knows(i,p)) {
			count++;
		}
	}
	return count>=n-1?p:-1;
}