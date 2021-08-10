#include <exception>
#include <iostream>
#include <vector>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        Element e;
        e.val = x;
        e.min = x;
        if (!c_.empty() && c_.back().min < e.min) {
            e.min = c_.back().min;
        }
        c_.push_back(e);
    }

    void pop() { c_.pop_back(); }

    int top() { return c_.back().val; }

    int getMin() { return c_.back().min; }

private:
    struct Element {
        int val;
        int min;
    };
    std::vector<Element> c_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}
