class Solution {
    
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),comp);
      int n=intervals.size();
      vector<int>temp=intervals[0];
      int ans=1;
      for(int i=1;i<n;i++){
           if(temp[1]>intervals[i][0]){
            
           }
           else{
             temp=intervals[i];
             ans++;
           }
      }
      return n-ans;
    }
};