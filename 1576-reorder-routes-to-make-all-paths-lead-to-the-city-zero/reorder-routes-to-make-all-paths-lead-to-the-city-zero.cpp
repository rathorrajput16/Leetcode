class Solution {
public:
     
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
       set<pair<int,int>>st;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            st.insert(make_pair(connections[i][0],connections[i][1]));
        }
        queue<int>q;
       q.push(0);
       int ans=0;
       vector<int>vis(n,0);
       vis[0]=1;
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           for(auto v:adj[it]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    if(st.find(make_pair(it,v))!=st.end())ans++;
                }
           }
       }
       return ans;
    }
};