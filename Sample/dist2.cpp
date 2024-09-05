#include <iostream>
#include <vector>
using namespace std;


void print(vector<vector<int>> arr) {
    for(auto a : arr) {
        for (int b : a) cout << b << " ";
        cout << "| ";
    }
    
    cout << endl;
}

bool check(vector<vector<int>> arr) {
    int n= arr.size();
    for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++) {
        if (arr[i][0] >= arr[j][0] && arr[i][0] <= arr[j][1]) return true;
        if (arr[i][1] >= arr[j][0] && arr[i][1] <= arr[j][1]) return true;
        if (arr[j][0] >= arr[i][0] && arr[j][0] <= arr[i][1]) return true;
        if (arr[j][1] >= arr[i][0] && arr[j][1] <= arr[i][1]) return true;
    }
    return false;
}

int distribution(vector<vector<int>> arr) {
    int n= arr.size();
    vector<vector<int>> grp1, grp2;
    int count=0;
    for(int i=0; i<n-2; i++) for(int j=i+1; j<n; j++) {
        grp1.push_back(arr[i]);
        grp1.push_back(arr[j]);
        for(int k=0; k<n ; k++) {
            if (k == i || k == j) continue;
            grp2.push_back(arr[k]);
        }
        //print(grp1);
        //print(grp2);
        int set1 = check(grp1);
        int set2 = check(grp2);
        if ( set1 && set2) {
            count++;
            cout << set1 << "  =  | "; print(grp1);
            cout << set2 << "  =  | "; print(grp2);
            cout << "------------------------------------------" << endl;
        } 
        
        
        
        grp1.clear();
        grp2.clear();
        if (count == 2) {
            int rem = n-(count*2);
            cout << "rem = " << rem << endl;
            return (rem+1)*2;
            break;
        }
    }
    if (count != 2) return 0;
    return 0;
}

int main() {

    vector<vector<int>> arr={{1,5},{3,8},{10,15},{13,14},{20,100},{30,40}};
    cout << distribution(arr);
    return 0;
}
