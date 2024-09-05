#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getsize(int score_count, int* score) {
    int count=0;
    for(int i=0; i<score_count; i++)
        if (score[i] != -1) count++;
    return count;
}
int get_max_L(int score_count,int* score, int m) {
    int max =-1,idx=0;
    for(int i=0; i<score_count; i++) {
        if (score[i] == -1) continue;
        if (score[i] > max) {
            max = score[i];
            idx=i;
            m--;
        }
        if (m <= 0) break;
    }
    return idx;
}
int get_max_R(int score_count,int* score, int m) {
    int max =-1,idx=0;
    for(int i=score_count-1; i>=0; i--) {
        if (score[i] == -1) continue;
        if (score[i] > max) {
            max = score[i];
            idx=i;
            m--;
        }
        if (m <= 0) break;
    }
    return idx;
}
int getMaxTeams(int score_count, int* score, int team , int m){
    int i=0, L=0 , R=0, toex=0, res=0;
    for(int t=0; t<team; t++) {
        L = get_max_L(score_count,score,m);
        R = get_max_R(score_count, score,m);
        if (score[L] == score[R]) {
            int temp = (L > R) ? R : L;
            toex = score[temp];
            score[temp] = -1;
        } else if (score[L] > score[R]) {
            toex = score[L];
            score[L] = -1;
        }else if (score[L] < score[R]) {
            toex = score[R];
            score[R] = -1;
        }
        res += toex;
        if (getsize(score_count, score) < m) break; 
    }
    
	return res;
    
}

int main() {
    
    int score[]={17,12,10,2,7,2,11,20,8};
    cout << getMaxTeams(9,score,3,4);
    
    return 0;
}