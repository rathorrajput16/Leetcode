class Solution {
public:
     int solve(vector<int>&ans){
        int m=ans.size();
        int maxi=0;
        int n=m;
        vector<int>nse(m,m);
        vector<int>pse(m,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&ans[st.top()]>=ans[i])st.pop();
            if(!st.empty())pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
         for(int i=n-1;i>=0;i--){
            while(!st.empty()&&ans[st.top()]>=ans[i])st.pop();
            if(!st.empty())nse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<m;i++){
                int left=i-pse[i];
                int right=nse[i]-i;
                int width=left+right-1;
                maxi=max(maxi,min(width,ans[i])*min(width,ans[i]));
        }
        return maxi;
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>prefix(m,0);
    
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(matrix[i][j]=='1')prefix[j]+=1;
                 else prefix[j]=0;
             }
             ans=max(solve(prefix),ans);
         }
        return ans;
    }
};