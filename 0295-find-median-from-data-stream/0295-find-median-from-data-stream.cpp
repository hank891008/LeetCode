class MedianFinder {
public:
    priority_queue<int>first;
    priority_queue<int, vector<int>, greater<int>> second;
    MedianFinder() {
    }
    
    void addNum(int num) {
        first.emplace(num);
        second.emplace(first.top());
        first.pop();
        if(first.size() < second.size()){
            first.emplace(second.top());
            second.pop();
        }
        
    }
    
    double findMedian() {
        if((first.size() + second.size()) % 2 == 0){
            return (first.top() + second.top()) / 2.;
        }
        else{
            return first.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */