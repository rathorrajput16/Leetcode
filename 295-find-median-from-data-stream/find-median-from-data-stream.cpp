class MedianFinder {
   using ll=long long;
public:

    priority_queue<ll>pq;
    priority_queue<ll,vector<ll>,greater<ll>>pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        if(pq.size()-pq1.size()>1){
            pq1.push(pq.top());
            pq.pop();
        }
        if(!pq1.empty()&&pq.top()>pq1.top()){
            ll val=pq.top();
            pq.pop();
            ll val2=pq1.top();
            pq1.pop();
            pq.push(val2);
            pq1.push(val);
        }
    }
    
    double findMedian() {
        if(pq.size()>pq1.size()){
            return pq.top();
        }
        else if(pq.size()<pq1.size()){
           return pq1.top();
        }
        return (pq.top()+pq1.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */