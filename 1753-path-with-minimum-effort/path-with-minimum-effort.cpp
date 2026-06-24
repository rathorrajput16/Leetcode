class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int>dirx={-1,1,0,0};
        vector<int>diry={0,0,1,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(dis>dist[row][col])continue;
            for(int i=0;i<4;i++){
                  int nr=row+dirx[i];
                  int nc=col+diry[i];
                  if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int curr=abs(heights[nr][nc]-heights[row][col]);
                    curr=max(curr,dis);
                    if(dist[nr][nc]>curr){
                        dist[nr][nc]=curr;
                        pq.push({curr,{nr,nc}});
                    }
                  }
            }
        }

        return dist[n-1][m-1];
    }
};