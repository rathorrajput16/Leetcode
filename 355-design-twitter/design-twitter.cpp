class Twitter {
    using ll=long long;
    int time;
    map<ll,set<ll>>mp;
    map<ll,vector<pair<ll,ll>>>t;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
         for(auto it:t[userId]){
            pq.push(it);
            if(pq.size()>10)pq.pop();
         }
         for(auto it:mp[userId]){
            for(auto f:t[it]){
                pq.push(f);
            if(pq.size()>10)pq.pop(); 
            }
         }
         while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */