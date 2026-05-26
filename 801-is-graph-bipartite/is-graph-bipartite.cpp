class Solution {
public:
 bool dfs(int i,vector<bool>&vis,vector<int>&col,int colr,vector<vector<int>>& adj){
                col[i]=1-colr;
                vis[i]=true;
            
                    for(auto v:adj[i]){
                        if(!vis[v]){
                            vis[v]=true;
                            col[v]=1-col[i];
                            if(!dfs(v,vis,col,1-col[v],adj))return false;
                        }
                        else if(vis[v]&&(col[v]==col[i])){
                            return false;
                        }
                    }
                
                return true;
}
   
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        
        vector<int>col(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
             if(!dfs(i,vis,col,1,adj))return false;
            }
        }
        
        return true;
            
    }
};