class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        int candies=n;
        int i=1;
        while(i<n){
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            int inc=0;
            int dec=0;
            while(i<n&&arr[i]>arr[i-1]){
               inc++;
                candies+=inc;
              
              i++;
            }
            while(i<n&&arr[i]<arr[i-1]){
                    dec++;
                   candies+=dec;
                  
                   i++;
            }
            candies-=min(inc,dec);
        }
        return candies;
    }
};