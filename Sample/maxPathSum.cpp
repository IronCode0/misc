#include<vector>
#include<iostream>
using namespace std;

int maxim(int a,int b,int c) {
    int m=0;
    if (a > m) m=a;
    if (b > m) m=b;
    if (c > m) m=c;
    return m;
}

int move(vector<vector<int>> mat, int i, int j) {
    if (i<0 || i>mat.size()-1 || j<0 || j>mat[0].size()-1 ) return 0;
    int L=move(mat,i+1,j-1);
    int M=move(mat,i+1,j  );
    int R=move(mat,i+1,j+1);
    return mat[i][j] + maxim(L,M,R); 
    //max(max(L,M),R)
}

int maxPathSum(vector<vector<int>> board,int p,int q){
    int a=move(board,0,p)-1;
    //cout << a;
    int b=move(board,board.size()-1,q)-1;
    //cout << endl << b << endl;
    return max(a,b);
}


int main() {
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << maxPathSum(v,2,3);
    return 0;
}