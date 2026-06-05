class Solution {
public:
  long long merge(long long low,long long mid,long long high,vector<long long>&nums){
     long long left=low;
     long long right=mid+1;
     long long ans=0;
     while(left<=mid&&right<=high){
        if(nums[left]>2*nums[right]){
          ans+=mid-left+1;
           right++;
        }
        else{
            left++;
        }

     }
     left=low;
     right=mid+1;

          vector<long long>temp;
     while(left<=mid&&right<=high){
          if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
          }
          else{
            temp.push_back(nums[right]);
            right++;
          }
     }

     while(left<=mid){
        temp.push_back(nums[left]);
            left++;
     }
     while(right<=high){
        temp.push_back(nums[right]);
            right++;
     }

      for(long long i=low;i<=high;i++){
        nums[i]=temp[i-low];
      }
    return ans;
  }
  long long mergesort(long long low,long long high,vector<long long>&arr){
    if(low>=high)return 0;
    long long cnt=0;
    long long mid=low+(high-low)/2;
    cnt+=mergesort(low,mid,arr);
    cnt+=mergesort(mid+1,high,arr);
    cnt+=merge(low,mid,high,arr);
    return cnt;
  }
    int reversePairs(vector<int>& nums) {
        vector<long long>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=nums[i];
        }
    
        return mergesort(0,nums.size()-1,arr);
    }
};