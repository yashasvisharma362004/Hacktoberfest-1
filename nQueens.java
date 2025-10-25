class Solution {
    static List < String > construct(char[][] board) {
        List < String > res = new LinkedList < String > ();
        for (int i = 0; i < board.length; i++) {
            String s = new String(board[i]);
            res.add(s);
        }
        return res;
    }
    public boolean  isValid(char board[][],int row,int col){
        //isme condns likhni h
        int duprow = row;
        int dupcol = col;
        //upper left diag
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        // reset row col now check left now
        row = duprow;
         col = dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q')return false;
                col--;
        }
            //reset row col check lower left diag
            row = duprow;
            col = dupcol;
            while(col >= 0 && row <board.length){
                if(board[row][col] == 'Q')return false;
                    col--;
                    row++;
            }
        return true;
    }
    public void solve(int col,char board[][],List<List<String>>result){
        if(col == board.length){
            result.add(construct(board));
            return;
        }
        for(int row = 0;row < board.length; row++){
            if(isValid(board,row,col)){
                board[row][col] = 'Q';
                //recursive call
                solve(col+1,board,result);
                //backtrack
                board[row][col] = '.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>>result = new ArrayList<>();
        char board[][] = new char[n][n];
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                board[i][j] = '.';
            }
        }
        solve(0,board,result);
        return result;
    }
}
