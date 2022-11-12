class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxheap.size() > 0 && num > maxheap.top())
        {
            minheap.push(num);
        }
        
        else
        {
            maxheap.push(num);
        }
        
        if(minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        if(maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        
        if(minheap.size() == maxheap.size())
        {
            return (minheap.top() + maxheap.top())/2.0;
        }
        
        if(minheap.size() > maxheap.size())
        {
            return minheap.top();
        }
        
        else
        {
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */