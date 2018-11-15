#include<iostream>
#include<vector>
using namespace std;
/*
155. 最小栈

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

 */

class MinStack {
public:
   /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        arr.push(x);
        if(arr_min.empty())arr_min.push(x);
        else arr_min.push(min(x,arr_min.top()));
    }
    
    void pop() {
        arr.pop();
        arr_min.pop();
    }
    
    int top() {
        return arr.top();
    }
    
    int getMin() {
        return arr_min.top();
    }
private:
    stack<int> arr;
    stack<int> arr_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */   
