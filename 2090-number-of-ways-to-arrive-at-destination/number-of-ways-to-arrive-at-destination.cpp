class Solution {
public:
using ll =long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll>ways(n,0);
         vector<long long> dist(n, LLONG_MAX);
        dist[0]=0;
        ways[0]=1;
        vector<vector<pair<ll,ll>>>adj(n);
        const ll mod=1e9+7;
        for(ll i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll curdis=it.first;
            ll node=it.second;
            if(curdis>dist[node])continue;
            for(auto v:adj[node]){
                if(dist[v.first]>dist[node]+v.second){
                    dist[v.first]=dist[node]+v.second;
                    ways[v.first]=ways[node];
                    pq.push({dist[v.first], v.first});
                }
                else if(dist[v.first]==dist[node]+v.second){
                    ways[v.first] =(ways[v.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};