class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        vector<int>indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
          auto it=q.front();
          q.pop();
          ans.push_back(it);
          for(int v:adj[it]){
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
          }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};