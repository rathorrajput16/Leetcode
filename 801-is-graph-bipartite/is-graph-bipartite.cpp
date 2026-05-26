class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        
        vector<int>col(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            queue<int>q;
                q.push(i);
                col[i]=1;
                vis[i]=true;
                while(!q.empty()){
                    auto it=q.front();
                    q.pop();
                    for(auto v:adj[it]){
                        if(!vis[v]){
                            vis[v]=true;
                            col[v]=1-col[it];
                            q.push(v);
                        }
                        else if(vis[v]&&(col[v]==col[it])){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};