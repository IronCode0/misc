#include <iostream>
#include <vector>
#include <set>
using namespace std;


int getMinuTrip(vector<int> w) {
    set<int> list ;
    for(int a : w) list.insert(a);
    int t=0, x=0;
    for(int b : list) {
        for(int c : w) if (c == b) x++;
        t +=(x/3) + ((x%3)/2);
        x=0;
    }
    return t ;
}

int main() {
    vector<int> w={2,4,6,6,4,2,4};
    cout << getMinuTrip(w);
    return 0;
}