class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double area=0;

        double low=0;
        double high=1e18;
        while((high-low)>1e-6){
            double mid=low+(high-low)/2;
            double temp=0;
            double temp1=0;
          for(int i=0;i<squares.size();i++){
           double top=squares[i][1]+squares[i][2];
           double bottom=squares[i][1];
            if(mid<top&&mid>bottom){
              double w1=top-mid;
               double w2=mid-bottom;
               temp+=1.0*squares[i][2]*w1;
               temp1+=1.0*squares[i][2]*w2;
            }
            else if(mid>=top){
                temp1+=1.0*squares[i][2]*squares[i][2];
            }
            else{
                temp+=1.0*squares[i][2]*squares[i][2];
            }
            }  
            if(temp<=temp1){
               high=mid;
            }   
            else{
                low=mid;
            }

        }
        return high;
    }
};