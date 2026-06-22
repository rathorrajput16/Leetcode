class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])cnt++;
                if(grid[i][j]==1&&(i==0||j==0||i==n-1||j==m-1)){
                     q.push({i,j});
                     vis[i][j]=1;
                }
            }
        }
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        int cnt1=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1)cnt1++;
            }
        }
        return cnt-cnt1;
    }
};