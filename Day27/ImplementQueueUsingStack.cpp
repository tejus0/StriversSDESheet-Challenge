#include <bits/stdc++.h> 
class Queue {
    int * arr;
  int start, end, Size;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[1000];
      start = 0;
      end = 0;
      Size = 1000;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return start==end ? true : false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (end == Size) {
      return;
        } else {
          arr[end] = data;
          end++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if (start==end) {
            return -1;
    }
    else{
        int front=arr[start];
        arr[start]=-1;
        start++;
        if(start==end){
            start=0;
            end=0;
        }
        return front;
    }
    }

    int front() {
        // Implement the front() function
        if (start == end) {
      return -1;
    }
    return arr[start];
    }

};