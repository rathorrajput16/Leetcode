class Solution {
public:
    int trap(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int lm=0;
        int rm=0;
        int ans=0;
        while(low<=high){
          if(height[low]<=height[high]){
                 if(lm<=height[low]){
                    lm=height[low];
                    
                 }
                 else{
                     ans+=(lm-height[low]);
                 }
                 low++;
          }
          else{
              if(rm<=height[high]){
                    rm=height[high];
                    
                 }
                 else{
                     ans+=(rm-height[high]);
                 }
                  high--;
          }
         
        }

            return ans;
    }
};