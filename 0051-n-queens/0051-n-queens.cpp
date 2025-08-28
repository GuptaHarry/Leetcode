class Solution {
public:
bool check( int n ,vector<string>&board,int row , int col ){
    // always need to check for two diagonals 
    // upperLEft   -1,-1
    // upperRight  -1 +1
    int i=row , j= col;
    while(i>-1 && j>-1){
        // upper Left 
        if(board[i][j]=='Q')
        return 0;

        i--;
        j--;
    }
    i=row ,j=col;
    // upper right 
    while( i>-1 && j<n){
        if(board[i][j]=='Q')
        return 0;
        i--;
        j++;
    }

 return 1; // base chekc 
}
 void find(int row,int n ,vector<vector<string>>&ans,vector<bool>&column, vector<string>&board){
    // base condtition
    if(row==n){
        ans.push_back(board);
        return ;
    }

    // check for eahc column for thaat row
    for(int j=0;j<n;j++){

         if(column[j]==0 && check(n,board,row,j)){

            // mark and pllace the quue n
            column[j]=1;
            board[row][j]='Q';
            // go for next row
            find(row+1,n,ans,column,board);
            // if retrunign from downwards with failire unmark them
            column[j]=0;
            board[row][j]='.';
         }
    }
 }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>board(n);
// intialse all the base values .
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');

        // vector to check current ocupancy/
        vector<bool>column(n,0);
         find(0,n,ans,column,board);
         
        
         return ans;
    }
};