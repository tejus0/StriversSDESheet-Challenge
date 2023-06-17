class MyStack {
public:
        queue<int> main;
        queue<int>temp;
    MyStack() {
    }
    
    void push(int x) {
        temp.push(x);
        while(main.size()){
            int y=main.front();
            temp.push(y);
            main.pop();
        }
        swap(temp,main);
    }
    
    int pop() {
        int y=main.front();
        main.pop();
        return y;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        return main.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */