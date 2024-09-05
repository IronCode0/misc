#include<vector>
#include<iostream>
using namespace std;

int maxCoins(int initialEnergy,vector<int> energy, vector<int> coins, int index, vector<vector<int>> mem) {
    if (initialEnergy < 0 || index > coins.size()) return 0;
    if (mem[index][initialEnergy] != 0) return mem[index][initialEnergy];
    else {
        int result = max(maxCoins(initialEnergy+energy[index-1]-1,energy,coins,index+1, mem),
                coins[index-1]+maxCoins(initialEnergy-1,energy,coins, index+1, mem));
        mem[index][initialEnergy] = result;
        return result;
    }
}
int getRich(long initialEnergy, vector<int> energy, vector<int> coins) {
    int energySum = initialEnergy;
    for (int i=0; i< energy.size();i++) energySum+=energy[i];
    vector<vector<int>> mem( coins.size()+1 , vector<int> (energySum, 0)); 
    return maxCoins(initialEnergy,energy,coins, 1, mem);
}

int main() {
    cout << endl <<getRich(0,{2,1,1},{11,5,7});
    return 0;
}