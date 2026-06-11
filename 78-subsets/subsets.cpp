class Solution {
    using ll=long long;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;
      ll n=nums.size();
      for(int i=0;i<(1LL<<n);i++){
          ll num=i;
          vector<int>temp;
          ll j=0;
           while(num>0){
            if(num&1){
            temp.push_back(nums[j]); 
           }
           j++;
           num=num>>1;
           }
           

          
          ans.push_back(temp);
      }  
      return ans;
    }
};