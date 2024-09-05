#include <iostream>
#include <vector>
using namespace std;

int r,c;
bool exist=false, exist_2=false;
//vector<vector<int>> board;

int move_forward(int i,int j,vector<vector<int>>& board,int count) {
    if (i<0 || i>=r || j<0 || j>=c || board[i][j] == -1) return count;
    if (board[i][j] == 1) {
        count++;
        board[i][j] = 0;
    }
    if (i == r-1 && j == c-1) {
        
        exist=true;
        return count;
    }
    //cout << "move to (" << i << "," << j << ") count=" << count << endl;
    int down  = move_forward(i+1, j  , board, count);
    int right = move_forward(i  , j+1, board, count);
    //board[i][j] = 1;
    return (down > right) ? down : right;
}
int move_backward(int i,int j,vector<vector<int>>& board,int count) {
    if (i<0 || i>=r || j<0 || j>=c || board[i][j] == -1) return count;
    if (board[i][j] == 1) {
        count++;
        board[i][j] = 0;
    }
    if (i == 0 && j == 0) {
        
        exist_2=true;
        return count;
    }
    //cout << "move to (" << i << "," << j << " count=" << count << endl;
    int up   = move_backward(i-1, j  , board, count);
    int left = move_backward(i  , j-1, board, count);
    return (up > left) ? up : left;
}
int collectMAX(vector<vector<int>>& board) {
    r= board.size();
    c= board[0].size();
    int e_count=0, collect_f=0 , collect_b=0;
    if (board[0][0] == 1) {e_count++; board[0][0]=0;}
    if (board[r-1][c-1] == 1) {e_count++; board[r-1][c-1]=0;};
    collect_f = move_forward(0,0,board,0);
    
    collect_b = move_backward(r-1,c-1,board,0);

    if (exist == false || exist_2== false ) return 0;       // path doenot exist
    if (exist) e_count +=collect_f;
    if (exist_2) e_count +=collect_b;
    return e_count;
}

int main() {
    
    /*board = {{ 1, 1,-1, 0}
            ,{ 1, 1, 0, 1}
            ,{-1, 0,-1, 1}
            ,{ 0, 0, 1, 1}};*/
    //vector<vector<int>> board = {{0,1,-1},{1,0,-1},{1,1,1}};
    vector<vector<int>> board = {{1,1,-1},{1,-1,1},{-1,1,1}};
    //vector<vector<int>> board = {{0,1},{-1,0}};
    cout << collectMAX(board);
    return 0;
}