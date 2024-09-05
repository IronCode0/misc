#include <iostream>
#include <vector>
#include <thread>
#include <iomanip> 
using namespace std;
#define min(a,b) (a > b) ? b : a
#define max(a,b) (a < b) ? b : a


long getXcount(long s) {
    long count=0;
    for(int i=0; i<s; i++) {
        long sum=0;
        vector<int> a;
        for(int j=i+1; j<=s; j++) {
            sum+=j;
            a.push_back(sum);
            //cout << sum << " ";
            if (sum == s) {
                for(int z : a) cout << z << " ";
                cout << endl;
                count++;
                break;
            }
            if (sum  > s) break;
        }
        //cout << endl << "---------" << endl;
        //count++;
    }
    return count;
}
int main() {
    
    cout << getXcount(500);
    return 0;
}