class StockSpanner {
public:
    stack<int>st;
    vector<int>arr;
    int ind;
    StockSpanner() {
        ind=0;
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty()&&arr[st.top()]<=price){
            st.pop();
        }
        int ans=0;
       if(st.empty())ans=ind+1;
       else ans=ind-st.top();
       st.push(ind);
         ind++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */