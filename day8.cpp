#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 15;
#define MOD 1000000007
bool itCycles(vector<string> vals, vector<string> ins) {
    map<int, bool> vis;

    ll acum = 0;
    int i = 0;
    while(i < (int) ins.size()) {
        if(vis[i]) return true;
        string in = ins[i];
        string val = vals[i];
        vis[i] = true;
        if(in == "nop") {
            i++;
        } else if(in == "acc") {
            char sign = val[0];
            int cuan = stoi(val.substr(1));
            if(sign == '+') acum += cuan;
            else acum -= cuan;
            i++;
        } else {
            char sign = val[0];
            int cuan = stoi(val.substr(1));
            if(sign == '+') i += cuan;
            else i -= cuan;
        }
    }

    cout << "no hay ciclo!!!" << endl;
    cout << acum << endl;
    return false;
}

int main() { _
    string in, val;
    vector<string> ins, vals;
    while(cin >> in >> val) {
        ins.push_back(in);
        vals.push_back(val);
    }

    for(int i = 0; i < ins.size(); i++) {
        if(ins[i] == "nop") {
            ins[i] = "jmp";
            itCycles(vals, ins);
            ins[i] = "nop";
        } else if(ins[i] == "jmp") {
            ins[i] = "nop";
            itCycles(vals, ins);
            ins[i] = "jmp";
        }
    }
    
    return 0;
}
