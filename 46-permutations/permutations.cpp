class Solution {
public:
   vector<vector<int>>ans;
   void f(int ind,vector<int>&arr){
    if(ind==arr.size()){
        ans.push_back(arr);
    }
    for(int i=ind;i<arr.size();i++){
        swap(arr[ind],arr[i]);
        f(ind+1,arr);
        swap(arr[ind],arr[i]);
    }

   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr=nums;
        f(0,nums);
return ans;
    }
};