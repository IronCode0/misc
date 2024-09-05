#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0; i<n; i++) {
        cout << "for i: " << i << endl;
        for(int j=0; j<i; j++) {
            cout << "  for j: "<< j << endl;
            cout << "    swap (" << i << "," << j << ") with (" << j << "," << i << ")" << endl; 
            swap(matrix[i][j],matrix[j][i]);
        }
        cout << endl;
    }
    for(int i=0; i<n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
    }

int main() {
    

    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    cout << endl;
    for (auto b : a) {
        for (auto c : b) cout << c << " ";
        cout << endl;
    }
    int z;
    cin >>z ;


}