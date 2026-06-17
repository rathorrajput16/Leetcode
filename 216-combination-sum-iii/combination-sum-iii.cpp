class Solution {
public:
   vector<vector<int>>ans;
       void f(int ind,vector<int>&arr,vector<int>&path,int k,int n){
          if(n==0&&path.size()==k){
            ans.push_back(path);
            return;
          }
          if(n<0)return;
          if(path.size()>k)return;
          if(ind==arr.size())return;
           if(arr[ind]<=n){
              path.push_back(arr[ind]);
                f(ind+1,arr,path,k,n-arr[ind]);
              path.pop_back();
           }
           f(ind+1,arr,path,k,n);
       }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        f(0,nums,path,k,n);
        return ans;
    }
};