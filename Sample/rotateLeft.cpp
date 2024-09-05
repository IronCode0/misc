#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int res=nums[0];
    for(int i=1;i<n;i++){
        bitset<8> x(i);
        cout << x << "\n";
        res=res^nums[i];
    }
    return res;
}

int main() {
    vector<int> arr{4,2,1,2,1};
    cout << singleNumber(arr);
    return 0;
}
