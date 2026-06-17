class Solution {
public:
vector<vector<int>>ans;
   void f(int ind,int target,vector<int>&path,vector<int>&arr){
        
   
            if(target==0){
                ans.push_back(path);
                return;
            }
            
          
          if(target<0)return;
          for(int i=ind;i<arr.size();i++){
            if(i>ind&&arr[i]==arr[i-1])continue;
            if(arr[i]<=target){
                path.push_back(arr[i]);
                f(i+1,target-arr[i],path,arr);
                path.pop_back();
            }
        

          }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
           vector<int>path;
           f(0,target,path,candidates);
           return ans;
    }
};