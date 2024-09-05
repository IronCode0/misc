#include <iostream>
#include <vector>
using namespace std;
enum class DIR{
    NONE = 0,
    UP = 1,
    LEFT = 2
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 1) return max(grid[0][0], 0);
        
        vector<vector<int>> dpf(n, vector<int>(n, 0));
        vector<vector<int>> dpb(n, vector<int>(n, 0));
        vector<vector<DIR>> from(n, vector<DIR>(n, DIR::NONE));
        
        //base case
        dpf[0][0] = grid[0][0];
        grid[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == -1){
                    dpf[i][j] = -1;
                }else{
                    if(i-1 >= 0 && dpf[i-1][j] != -1){
                        if(dpf[i-1][j]+grid[i][j] > dpf[i][j]){
                            dpf[i][j] = dpf[i-1][j]+grid[i][j];
                            from[i][j] = DIR::UP;
                        }
                    }
                    if(j-1 >= 0 && dpf[i][j-1] != -1){
                        if(dpf[i][j-1]+grid[i][j] > dpf[i][j]){
                            dpf[i][j] = dpf[i][j-1]+grid[i][j];
                            from[i][j] = DIR::LEFT;
                        }
                    }
                }
            }
        }
        
        int i = n-1, j = n-1;
        while(i != 0 || j != 0){
            if(grid[i][j] > 0) grid[i][j] = 0;
            if(from[i][j] == DIR::LEFT){
                --j;
            }else if(from[i][j] == DIR::UP){
                --i;
            }else{
                return 0;
            }
        }
        
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(dpf[i][j] == -1){
                    dpb[i][j] = -1;
                }else{
                    if(i+1 < n && dpb[i+1][j] != -1){
                        dpb[i][j] = max(dpb[i+1][j]+grid[i][j], dpb[i][j]);
                    }
                    if(j+1 < n && dpb[i][j+1] != -1){
                        dpb[i][j] = max(dpb[i][j+1]+grid[i][j], dpb[i][j]);
                    }
                }
            }
        }

        
        return dpf[n-1][n-1] + dpb[0][0];
    }
};

int main() {
    vector<vector<int>> board = {
        {1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,1,1,1}
    };
    board = {{0,1},{-1,0}};
    Solution a;
    cout << a.cherryPickup(board);
    /*board = {{ 1, 1,-1, 0}
            ,{ 1, 1, 0, 1}
            ,{-1, 0,-1, 1}
            ,{ 0, 0, 1, 1}};*/
    // vector<vector<int>> board = {{0,1},{-1,0}};
    //cout << collectMAX(board);
    return 0;
}