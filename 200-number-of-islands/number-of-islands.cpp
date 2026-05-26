class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<int>dx={-1,1,0,0};
      vector<int>dy={0,0,1,-1};
      int cnt=0;
      vector<vector<bool>>vis(n,vector<bool>(m,false));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&grid[i][j]=='1'){
                cnt++;
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    auto it=q.front();
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nr=it.first+dx[i];
                        int nc=it.second+dy[i];
                        if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                            vis[nr][nc]=1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
      }
      return cnt;
    }
};