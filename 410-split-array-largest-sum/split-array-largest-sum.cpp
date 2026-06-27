class Solution {
public:
 int check(vector<int>&arr,int k,int mid){
          int p=1;
          int sum=0;
          for(int i=0;i<arr.size();i++){
             
              if(sum+arr[i]>mid){
                 sum=arr[i];
                 p++;   
              }    
              else{
             sum+=arr[i];
              }
          }
          return p;
         }   
    
    int splitArray(vector<int>& nums, int k) {
        vector<int>arr=nums;
    if(k>arr.size())return -1;
    int maxi=0;
    int high=0;
    int ans=-1;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
        high+=arr[i];
    }
    int low=maxi;
    while(low<=high){
        int mid=low+(high-low)/2;
     int p=check(arr,k,mid);
     if(p>k){
         low=mid+1;
     }
     else{
        ans=mid;
         high=mid-1;
     }
    }
    return ans;
    }
};