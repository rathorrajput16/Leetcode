class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int cnt=1;
        int n=points.size();
        if(n==0)return 0;
        vector<int>temp=points[0];
        for(int i=1;i<n;i++){
            if(points[i][0]<=temp[1]){

            }
            else{
                cnt++;
                temp=points[i];
            }
        }
        return cnt;
    }
};