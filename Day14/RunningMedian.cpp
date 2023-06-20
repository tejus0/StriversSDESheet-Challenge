// Time - O(N * LOG( N))  Space - O(N)

#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    if(n==0)    return ;
    priority_queue<int> mx;  
    priority_queue<int, vector<int>, greater<int>> mn;
    mx.push(arr[0]);
    cout<<mx.top()<<" ";
    for(int i=1; i<n; i++){
        if(mx.size()==0)
            mx.push(arr[i]);
        int x=arr[i];
        if(mx.size()> mn.size()){
            if(x< mx.top()){
                mn.push(mx.top());
                mx.pop();
                mx.push(x);
            }
            else{
                mn.push(x);
            }
            // cout << (mx.top() + mn.top())/2 << " ";
        }
        else{
            if(x < mx.top())
                mx.push(x);
            else {
              mn.push(x);
              mx.push(mn.top());
              mn.pop();
            }
            // cout<< mx.top()<<" ";
        }
        if(mx.size() == mn.size())
            cout << (mx.top() + mn.top())/2 << " ";
        else cout << mx.top() << " ";  
    }
}