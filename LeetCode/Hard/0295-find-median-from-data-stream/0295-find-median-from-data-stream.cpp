class MedianFinder {
public:
    priority_queue<int> maxHeapLeft;
    priority_queue<int, vector<int>, greater<int>> minHeapRight;

    MedianFinder() {

    }

    void addNum(int num) {

        if (maxHeapLeft.empty() || num <= maxHeapLeft.top()) {
            maxHeapLeft.push(num);
        } else {
            minHeapRight.push(num);
        }

        if (maxHeapLeft.size() > minHeapRight.size() + 1) {
            minHeapRight.push(maxHeapLeft.top());
            maxHeapLeft.pop();
        }
        else if (maxHeapLeft.size() < minHeapRight.size()) {
            maxHeapLeft.push(minHeapRight.top());
            minHeapRight.pop();
        }
    }

    double findMedian() {

        if (maxHeapLeft.size() == minHeapRight.size()) {
            return (maxHeapLeft.top() + minHeapRight.top()) / 2.0;
        }

        return maxHeapLeft.top();
    }
};