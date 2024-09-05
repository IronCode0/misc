//#include<vector>
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int small(int x, int y, int z) {

    int s = 9999;

    if (x < s ) s=x;
    if (y < s ) s=y;
    if (z < s ) s=z;

    return s;
}
int get_min(vector<vector<int>> mat, int i, int j) {
    if (j=0) {
        if (mat[i+1][j] > mat[i+1][j+1]) return j+1;
        else return j;
    } else if (j=mat.size()-1) {
        if (mat[i+1][j-1] > mat[i+1][j]) return j;
        else return j-1
    } else {

        return min(min(mat[i+1][j-1],mat[i+1][j]),mat[i+1][j+1]);
    }
}
int move(vector<vector<int>> mat, int i, int j) {
    int m=mat[i][j];
    for(int k=0; k <3; k++) {
        m +=get_min(mat,k,j);
    }
    return m;
}
int move2(vector<vector<int>> mat, int i, int j) {
    if (i<0 || i>mat.size()-1 || j<0 || j>mat[0].size()-1 ) return 0;
    int L=move(mat,i+1,j-1);
    int M=move(mat,i+1,j  );
    int R=move(mat,i+1,j+1);
    //cout << "\t" << small(L,M,R);
    return mat[i][j] + small(L,M,R);
}
int maxEnergy(vector<vector<int>> mat) {
    int a=move(mat,0,0);
    int b=move(mat,0,1);
    int c=move(mat,0,2);
    int d=move(mat,0,3);
    cout << a << "\t" << b << "\t" << c << "\t" << d << endl;
    return 100 - min(small(a,b,c),d);
}

int main() {
    vector<vector<int>> v = {
        {10,20,30,40},
        {60,50,20,80},
        {10,10,10,10},
        {60,50,60,50}
    };
    cout << maxEnergy(v);
    return 0;
}