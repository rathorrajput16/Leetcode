class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(int row,int col,vector<string>&board,int n){
        for(int i=0;i<n;i++){
          if(i==col)continue;
          else if(board[row][i]=='Q')return false;
        }
        for(int i=0;i<n;i++){
          if(i==row)continue;
          else if(board[i][col]=='Q')return false;
        }
        int r=row-1;
        int c=col-1;
        while(r>=0&&c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=row-1;
        c=col+1;
        while(r>=0&&c<n){
             if(board[r][c]=='Q')return false;
            r--;
            c++;
        }
        

        return true;
    }
    void f(int i,int n,vector<string>&board){
        if(i==n){
            ans.push_back(board);
            return;
        }
        int row=i;
            for(int col=0;col<n;col++){
                if(issafe(row,col,board,n)){
                    board[row][col]='Q';
                       f(row+1,n,board);
                     board[row][col]='.';
                }
            }
        
    }
    vector<vector<string>> solveNQueens(int n) {
      string s;
      for(int i=0;i<n;i++)s+='.';
      vector<string>board(n,s);
      f(0,n,board);
      return ans;
    }
};