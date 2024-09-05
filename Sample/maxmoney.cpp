#include<stdio.h>
#include<string.h>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
*/

const short driverAge=16;


int fmax(int input1, int input2[], int input3[], int target) {
    int max =-1;
    for(int i=0; i<input1; i++)
        if (input3[i] == target && input2[i] > max)
            max = input2[i];
    return max;
}
int maxmoney(int input1, int input2[], int input3[]) {
    set<int> s;
    for(int i=0; i<input1; i++) s.insert(input3[i]);    
    vector<int> v(s.begin(),s.end());
    sort(v.begin(),v.end());
    int time=0, count=0;
    for(int j=0; j< v.size(); j++) {
        if (time == v[j]) break;
        
        int max =-1;
        for(int k=0; k<input1; k++)
            if (input3[k] == v[j] && input2[k] > max)
                max = input2[k];
    
        count +=max;
        time++;
    } 
    return count;
}

int main() {
    //int input3_2[] = {60,40,60,80};
    //int input3_3[] = {1,2,1,2};
    //cout << fmax(4,input3_2,input3_3,2);
    //return 0;
    cout << driverAge;
    int input1_2[] = {20,54,41};
    int input1_3[] = {3,4,5};
    
    int input2_2[] = {60,40,80};
    int input2_3[] = {1,2,2};
    cout << maxmoney(3,input1_2,input1_3) << "\n";
    cout << maxmoney(3,input2_2,input2_3);
    return 0;
}