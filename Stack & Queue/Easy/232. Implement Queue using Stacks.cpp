// Two Stacks Approach

class MyQueue {
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int result = s1.top();
        s1.pop();
        return result;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

// Single Stack Implementation

class MyQueue {
    stack<int> s1;

public:
    MyQueue() {}

    void push(int x) {
        stack<int> s2;
        assert(s2.empty());
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        assert(s2.empty());
    }

    int pop() {
        int result = s1.top();
        s1.pop();
        return result;
    }

    int peek() { 
      return s1.top(); 
    }

    bool empty() { 
      return s1.empty(); 
    }
};
