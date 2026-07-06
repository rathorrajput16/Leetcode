class Solution {
public:
    int f(int i,vector<int>&arr,int k,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=INT_MIN;
        int maxo=INT_MIN;
        for(int j=i;j<min(i+k,(int)arr.size());j++){
            maxo=max(maxo,arr[j]);
            maxi=max(maxi,maxo*(j-i+1)+f(j+1,arr,k,dp));
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};