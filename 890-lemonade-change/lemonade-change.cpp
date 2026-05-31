class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>freq;
        freq[5]=0;
        freq[10]=0;
        freq[20]=0;
         
        for(int i=0;i<bills.size();i++){
  
            if(bills[i]==10&&freq[5]>0){
                freq[5]--;
                freq[10]++;
            }
            else if(bills[i]==5){
                freq[5]++;
                
            }
            else if(bills[i]==20){
               if(freq[10]>0&&freq[5]>0){
                     freq[10]--;
                     freq[5]--;
               } 
               else if(freq[5]>=3){
                     freq[5]-=3;
               }
               else{
                return false;
               }
            }
            else{
                return false;
            }
        }
       
      return true;
    }
};