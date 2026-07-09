class DSU{
public:
vector<int>parent;
vector<int>size;
    DSU(int n){
    parent.resize(n);
    size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
         if (pu == pv)
            return;
        if(size[pu]<size[pv]){
               size[pv]+=size[pu];
               parent[pu]=pv;
        }
        else{
             size[pu]+=size[pv];
               parent[pv]=pu;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU dsu(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    dsu.unite(i,j);
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(dsu.find(i));
        }
        return st.size();

    }
};