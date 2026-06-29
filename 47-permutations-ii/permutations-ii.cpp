class Solution {
public:
       vector<vector<int>>ans;
   void f(int ind,vector<int>&arr){
    if(ind==arr.size()){
        ans.push_back(arr);
    }
    unordered_set<int>st;
    for(int i=ind;i<arr.size();i++){
         if(st.count(arr[i]))continue;
        swap(arr[ind],arr[i]);
        st.insert(arr[ind]);
        f(ind+1,arr);
        swap(arr[ind],arr[i]);
    }

   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          f(0, nums);
        return ans;
    }
};