class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {}

    void push(int value) {
        mainStack.push(value);

        if (minStack.empty() || minStack.top() >= value) {
            minStack.push(value);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            return;
        }
        int poppedValue = mainStack.top();
        mainStack.pop();

        if (poppedValue == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        if (minStack.empty()) {
            return -1;
        }

        return mainStack.top();
    }

    int getMin() {
        if (minStack.empty()) {
            return -1;
        }

        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
