class Solution {
public:
    void dfs(int i,vector<bool>&vis,vector<vector<int>>&adj){
        vis[i]=true;
        for(auto child:adj[i]){
           if(!vis[child]){
            dfs(child,vis,adj);
           }
        }
    
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               cnt++;
               dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};