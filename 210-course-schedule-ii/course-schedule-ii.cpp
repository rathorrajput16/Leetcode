class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
     
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       
        vector<int>ans;
        queue<int>q;
         for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto v:adj[it]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        vector<int>res;
        if(ans.size()<n)return res;
        else return ans;
    }
};