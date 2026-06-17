class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<m;i++){
           pq.push({heightMap[0][i],{0,i}});
            vis[0][i]=1;
           if(n>1)pq.push({heightMap[n-1][i],{n-1,i}});
            vis[n-1][i]=1;
        }
        for(int i=1;i<n-1;i++){
            pq.push({heightMap[i][0],{i,0}});
             vis[i][0]=1;
            if(m>1) pq.push({heightMap[i][m-1],{i,m-1}});
             vis[i][m-1]=1;
        }
        vector<int>dirx={-1,0,1,0};
        vector<int>diry={0,1,0,-1};
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int val=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int nr=row+dirx[i];
                int nc=col+diry[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]){
                      vis[nr][nc]=1;
                      ans+=max(0,val-heightMap[nr][nc]);
                      pq.push({max(heightMap[nr][nc],val),{nr,nc}});
                }
            }
        }
        return ans;
    }
};