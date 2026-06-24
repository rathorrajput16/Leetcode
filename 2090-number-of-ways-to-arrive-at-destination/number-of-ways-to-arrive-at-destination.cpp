class Solution {
public:
const long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<int>ways(n,0);
        vector<long long>dist(n,1e18);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            int node=it.second;
            if(dist[node]<dis)continue;
            for(auto v:adj[node]){
               if(dis+v.second<dist[v.first]){
                  dist[v.first]=dis+v.second;
                  ways[v.first]=ways[node];
                  pq.push({dist[v.first],v.first});
               }
               else if(dis+v.second==dist[v.first]){
                          ways[v.first]=(ways[v.first]+ways[node])%mod;
               } 
        
            }
        }
        return ways[n-1] ;
    }
};