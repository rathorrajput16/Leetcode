class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        pq.push({0,{0,src}});
        vector<int>stops(n,1e9);
        
        stops[src]=0;
        while(!pq.empty()){
              auto it=pq.top();
              pq.pop();
              int s=it.first;
              int p=it.second.first;
              int v=it.second.second;
              if(s>k)continue;
              for(auto u:adj[v]){
                 if(stops[u.first]>p+u.second){
                    stops[u.first]=p+u.second;
                    pq.push({s+1,{stops[u.first],u.first}});
                 }
              }
        }
        if(stops[dst]!=1e9)return stops[dst];
        return -1;

    }
};