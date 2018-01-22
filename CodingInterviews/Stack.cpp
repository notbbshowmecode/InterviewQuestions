class Solution {
private:
    stack<int> stk;
    stack<int> minStk;

public:
    void push(int value) {
        stk.push(value);
        if (minStk.empty() || value < minStk.top()) {
            minStk.push(value);
            return;
        }
        minStk.push(minStk.top());
    }

    void pop() {
        stk.pop();
        minStk.pop();    
    }

    int top() {
        return stk.top();
    }

    int min() {
        return minStk.top();
    }
};