class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=0;
        int n=ratings.size();
        int candies=n;
        while(i<n-1){
            if(ratings[i]==ratings[i+1]){
                i++;
                continue;
            }
            int inc=0;
            while(i+1<n&&ratings[i]<ratings[i+1]){
             
                 i++;
                inc++;
                    candies+=inc;
            }
            int dec=0;
            while(i+1<n&&ratings[i]>ratings[i+1]){
                i++;
                dec++;
                                candies+=dec;

            }
            candies-=min(inc,dec);
        }
        return candies;
    }
};