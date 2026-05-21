class Twitter {
    using ll=long long;
public:

    int time;
    Twitter() {
       time=0;
    }
   
    unordered_map<ll,set<ll>>follows;
    unordered_map<ll,vector<pair<ll,ll>>>tweets;
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
         priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        for(int i=max(0LL,(ll)(tweets[userId].size()-10));i<tweets[userId].size();i++){
            pq.push({tweets[userId][i].first,tweets[userId][i].second});
            if(pq.size()>10)pq.pop();
        }
        if(pq.size()>10)pq.pop();
        for(auto it:follows[userId]){
             for(int i=max(0LL,(ll)(tweets[it].size()-10));i<tweets[it].size();i++){
            pq.push({tweets[it][i].first,tweets[it][i].second});
            if(pq.size()>10)pq.pop();
        }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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