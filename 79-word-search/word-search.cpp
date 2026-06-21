class Solution {
public:
    bool f(int row,int col,vector<vector<char>>& board, string word,int ind){
        if(ind==word.size())return true;
        if(row<0||row>=board.size()||col<0||col>=board[0].size())return false;
        

        if(board[row][col]==word[ind]){
            board[row][col]='#';
            if(f(row+1,col,board,word,ind+1)||f(row,col+1,board,word,ind+1)||f(row-1,col,board,word,ind+1)||f(row,col-1,board,word,ind+1))return true;;
            board[row][col]=word[ind];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
         if(board[i][j]==word[0]){

            if(f(i,j,board,word,0))return true;
         }
       }
        }
        return false;
    }
};