class Solution {
public:
    bool f(vector<int>& arr, int ind,vector<int>& vis){
        if(ind<0||ind>=arr.size()||vis[ind])return false;
        if(arr[ind]==0)return true;
        vis[ind]=1;
        if(f(arr,ind+arr[ind],vis)||f(arr,ind-arr[ind],vis))return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
          vector<int> vis(arr.size(), 0);
         
        return f(arr,start,vis);

    }
};