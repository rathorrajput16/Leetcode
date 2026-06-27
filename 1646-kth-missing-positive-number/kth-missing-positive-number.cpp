class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=arr[mid];
            int diff=val-(mid+1);
            if(diff<k)low=mid+1;
            else{
                high=mid-1;
            }
        }
        if(high == -1)return k;
        return arr[high]+(k-(arr[high]-(high+1)));
    }
};