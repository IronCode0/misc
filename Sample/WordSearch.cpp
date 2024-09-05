#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int r,c;
    bool check_next(int i, int j, vector<vector<char>>& board, string word, unsigned int w_loc) {
        if (w_loc >= word.size()) return true;
        if (i<0 || i>=r || j<0 || j>=c || board[i][j] != word[w_loc]) return false;
        char t=board[i][j];
        board[i][j]= '#';
        if (check_next(i  , j+1, board, word, w_loc+1)) return true;
        if (check_next(i+1, j  , board, word, w_loc+1)) return true;
        if (check_next(i  , j-1, board, word, w_loc+1)) return true;
        if (check_next(i-1, j  , board, word, w_loc+1)) return true;
        board[i][j] = t;
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        r= board.size();
        c= board[0].size();
        for(int i=0; i<r; i++) for(int j=0; j<c; j++)
            if(check_next(i,j,board,word,0)) return true;
        return false;
    }
        
};

int main() {

    vector<vector<char>> board = {{'A','B','C','E'}
                                 ,{'S','F','C','S'}
                                 ,{'A','D','E','E'}};
    string word = "ABCCED";
    Solution a;
    cout << a.exist(board, "ABCCED") << endl;
    cout << a.exist(board, "ABCB") << endl;
    cout << a.exist(board, "SEE") << endl;
    return 0;
}


/*
class Solution {
    pair<int,int> find(vector<vector<char>>& board,char f) {
        int n=board.size();
        int m=board[0].size();
        int index =0;
        for(int i=0; i<n; i++) for (int j=0; j<m; j++) {
            if (board[i][j]==f) return {i,j};
        }
        return {0,0};
    }
    bool word_check(vector<vector<char>>& board, string word,int r, int c) {
        int n=board.size();     // row
        int m=board[0].size();  // col
        int w=word.size();
        int w_loc=0;
        cout << "check for (" << r << "," << c << ")" << endl;
        while(true) {
            //cout << r << "-" << c << " : " 
            //     << word[w_loc] << endl;
            if (c+1 <m) {  // on right side
                if (board[r][c+1] == word[w_loc+1]) {
                cout << "Condition Right" << endl;
                    w_loc++;
                    //if (++w_loc > w) break;
                    c++;
                    continue;
                }
            }
            if (c-1 >=0) {  // on left side
                if (board[r][c-1] == word[w_loc+1]) {
                cout << "Condition Left" << endl;
                    w_loc++;//if (++w_loc > w) break;
                    c--;
                    continue;
                }
            }
            if (r-1 >=0) {  // on Up side
                
                if (board[r-1][c] == word[w_loc+1]) {
                    cout << "Condition up" << endl;
                    w_loc++;//if (++w_loc > w) break;
                    r--;
                    continue;
                }
            }
            if (r+1 <n) {  // on Down side
                cout << r << " " << c << " " << word[w_loc+1] << endl;
                if (board[r+1][c] == word[w_loc+1]) {
                    cout << "Condition down" << endl;
                    cout << "code 474" << endl;
                    w_loc++;//if (++w_loc > w) break;
                    r++;
                    continue;
                }
            }
            //cout << "w= " << w-1 << "\tw_loc= " << w_loc << endl;
            if (w_loc == w-1) break;
                //cout << "code 458: " << r << "-" << c << endl;
            
            //cout << "code 885: " << r << "-" << c << endl
            //     << word[w_loc] << " --- " << word[w_loc+1] << endl;
            //cout << "code 785: " << board[r][c] << endl;
            return false;
        }
        return true;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();     // row
        int m=board[0].size();  // col
        int w=word.size();
        //cout << "n=" << n << endl
        //     << "m=" << m << endl
        //     << "w=" << w << endl;
        int w_loc=0;
        int r=-1,c=-1;
        char start = word[w_loc];
        bool flag =false;
        //cout << "result: " << word_check(board, word,1,3) << endl;
        //return false;


        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
            if (board[i][j]==start) {
                r =i, c=j;
                cout << "result: " << word_check(board, word,i,j) << endl;
                //if (word_check(board, word,i,j)) return true;
                //cout << i << "-" << j << " : " << board[i][j] << "-" << start << endl;
                //break;
                //flag = true;
            }
            
            }
            //if (r != -1 && c !=-1) break;
        }
        return false;
        //cout << r << "-" << c << " : " << endl;
        
    }
};
*/