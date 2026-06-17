class Solution {
public:
vector<vector<int>>ans;
   void f(int ind,vector<int>&path,vector<int>&arr){
        
                ans.push_back(path);
          if(ind>=arr.size())return;
          for(int i=ind;i<arr.size();i++){
            if(i>ind&&arr[i]==arr[i-1])continue;
     
                path.push_back(arr[i]);
                f(i+1,path,arr);
                path.pop_back();
  
        

          }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>path;
        f(0,path,nums);
        return ans;
    }
};