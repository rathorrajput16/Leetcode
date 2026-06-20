class Solution {
public:
  int n=9;
    bool issafe(vector<vector<char>>& board,int row,int col,char ch){
           for(int i=0;i<9;i++){
            if(i==col)continue;
            if(board[row][i]==ch)return false;
           }
           for(int i=0;i<9;i++){
            if(i==row)continue;
            if(board[i][col]==ch)return false;
           }
           int r=row/3;
           r=r*3;
           int c=col/3;
           c=c*3;
           for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(i==row&&j==col)continue;
                if(board[i][j]==ch)return false; 
            }
           }
           return true;
    }
    bool f(vector<vector<char>>& board){
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
     
             if(board[i][j]=='.'){
         
                for(char ch='1';ch<='9';ch++){
                   if(issafe(board,i,j,ch)){
                    board[i][j]=ch;

                      if(f(board))return true;
                    board[i][j]='.';
                }
            }
            return false;
             }
            
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
    
       f(board);
   
        
    }
};