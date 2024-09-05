#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

string rtrim(const string &);
vector<string> split(const string &);

map<string, string> db;

vector<string> implementAPI(vector<string> logs) {
    int n=logs.size();
    vector<string> output(n);
    vector<string> a_temp;
    for(int i=0; i<n; i++) {
        a_temp = split(logs[i]);
        if (a_temp[0]=="register") {
            db.insert(pair<string, string>(a_temp[1],a_temp[2]));
            output[i]="Registered sucessfuly";
        } else if (a_temp[0]=="login") {
            if (db[a_temp[1]] == a_temp[2])
                output[i]="Logged In sucessfuly";
            else output[i]="Login Unsucessfuly";
        } else if (a_temp[0]=="logout") {
            output[i]="Logged Out sucessfuly";
        }
    }
    return output ;
}

int main() {
    vector<string> w={"register david david123"
                      ,"register adam 1Adam1"
                      ,"login david david123"
                      ,"login adam 1adam1"
                      ,"logout david"};
    vector<string> output = implementAPI(w);
    for(string a : output) cout << a << endl;
    return 0;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
