class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int>row;
        set<int>col;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(mat[i][j]==0){
                   row.insert(i);
                   col.insert(j);
              }
            }
        }
        for(auto it:row){
            for(int i=0;i<m;i++){
                mat[it][i]=0;
            }
        }
        for(auto it:col){
            for(int i=0;i<n;i++){
                mat[i][it]=0;
            }
        }
    }
};