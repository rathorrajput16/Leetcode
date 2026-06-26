class MedianFinder {
    using ll=long long;
public:
    priority_queue<ll>maxi;
    priority_queue<ll,vector<ll>,greater<ll>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty()||maxi.top()>=num){
            maxi.push(num);
        }
        else mini.push(num);
        if(maxi.size()>mini.size()+1){
            ll n=maxi.top();
            maxi.pop();
            mini.push(n);
        }
        if(mini.size()>maxi.size()+1){
            ll n=mini.top();
            mini.pop();
            maxi.push(n);
        }
    }
    
    double findMedian() {
        int s=maxi.size()+mini.size();
        if(s%2){
            if(maxi.size()>mini.size())return maxi.top();
            return mini.top();
        }
        else{
            return (maxi.top()+mini.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */