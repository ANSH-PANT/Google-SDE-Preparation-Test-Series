/*
Time Complexity:
addNum(): O(log n)
findMedian(): O(1)
Space Complexity: O(n)
*/

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}
    void addNum(int num) {
        if (right.empty()) {
            right.push(num);
        } 
        else if (left.size() == right.size()) {
            if (num >= left.top()) {
                right.push(num);
            } 
            else {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        } 
        else {
            if (num <= right.top()) {
                left.push(num);
            } 
            else {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
    }
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / (double)2;
        } 
        else {
            return right.top();
        }
    }
};
