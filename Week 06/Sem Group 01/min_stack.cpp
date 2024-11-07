class MinStack {
public:

    int minNum = INT_MAX;
    stack<int> container;

    void push(int val) {
        if (val <= minNum)
        {
            container.push(minNum);
            minNum = val;
        }

        container.push(val);
    }

    void pop() {

        if (container.top() == minNum)
        {
            container.pop();
            minNum = container.top();
            container.pop();
        }

        else
        {
            container.pop();
        }

    }

    int top() {
        return container.top();
    }

    int getMin() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */