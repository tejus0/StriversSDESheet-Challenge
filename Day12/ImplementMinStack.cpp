// Brute Force Approach - Pairs (val, min till now )
// Time - O(1)  Space - O(2*N)

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};


// Two Stack Approach 

#include <bits/stdc++.h> 
// Implement class for minStack.

class minStack {
  stack <int> st;
  stack<int>min_st;
  public:

    void push(int x) {
      if(min_st.empty() || x <= min_st.top()){
        min_st.push(x);
      }
      st.push(x);
    }

  int pop() {
    if(st.empty())
      return -1;
    if(st.top()==min_st.top())
      min_st.pop();
    int x= st.top();
    st.pop();
    return x;
  }

  int top() {
    return st.empty() ? -1 : st.top();
  }

  int getMin() {
    return min_st.empty() ? -1 : min_st.top();
  }
};