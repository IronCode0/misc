#include <iostream>
using namespace std;

int candle(int k, int a, int b) {
    int diff = abs(a-b);
    int count=0;
    if (diff == k/2)
        count = k-2;
    else if (diff < k/2)
        count = diff-1;
    else if (diff > k/2)
        count = k-diff-1;
    return count;
}

int main() {
    int k,a,b;
    cin >> k;
    cin >> a;
    cin >> b;
    cout << candle(k,a,b) << endl;
    return 0;
}