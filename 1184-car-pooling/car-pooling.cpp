class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int>mpa,mpd;
        set<int>arr,dept;
        for(int i=0;i<trips.size();i++){
            int n=trips[i][0];
            int a=trips[i][1];
            int b=trips[i][2];
            mpa[a]+=n;
            mpd[b]+=n;
            arr.insert(a);
            dept.insert(b);
        }
        int i=0;
        int j=0;
        vector<int>a,b;
        for(auto it:arr){
            a.push_back(it);
        }
        for(auto it:dept){
            b.push_back(it);
        }
        int ans=0;
        int maxi=0;
        while(i<a.size()){
              if(a[i]<b[j]){
                ans+=mpa[a[i]];
                maxi=max(ans,maxi);
                i++;
              }
              else{
                ans-=mpd[b[j]];
                maxi=max(ans,maxi);
                j++;
              }
        }
        return maxi<=capacity;
    }
};