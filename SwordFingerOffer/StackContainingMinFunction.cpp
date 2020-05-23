/**
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小
 * 元素的min函数（时间复杂度应为O（1））。
 * 注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
 */

class Solution {
public:
    void push(int value) {
        s.push(value);
        if (mins.empty())
            mins.push(value);
        else if (mins.top() > value)
            mins.push(value);
    }
    void pop() {
        if (s.top() == mins.top())
            mins.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
private:
    stack<int> s;
    stack<int> mins;
};