#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>>que;
    int gk;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       gk=k;
       for(auto& it: arr){
           que.push(it);
        //    if(que.size()<k) que.push(it);
        //    else if(que.size()==k and it>=que.top()) que.push(it);
           if(que.size()>gk) que.pop();
       }
    }

    void add(int num) {
        // Write your code here.
        que.push(num);
        if(que.size()>gk)   que.pop();
    }

    int getKthLargest() {
       // Write your code here.
       return que.top();
    }

};