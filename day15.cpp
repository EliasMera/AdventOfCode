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

int solve(vector<int> arr, int n) {
    unordered_map<int, ll> mp;

    FOR(i, 0, (int) arr.size() - 1) mp[arr[i]] = i;
    arr.reserve(n);

    while(1) {
        int lst = arr.back();
        auto it = mp.find(lst);
        if(it == mp.end()) {
            arr.push_back(0);
        } else {
            int dist = (int) arr.size() - 1 - it->second;
            arr.push_back(dist);
        }

        mp[lst] = (int) arr.size() - 2;
        if(arr.size() == n) return arr.back();
    }

    return 0;
}

int main() { _

    cout << solve({3,1,2}, 30000000) << endl;
    cout << "Part 1: " << solve({7,12,1,0,16,2}, 2020) << endl;
    cout << "Part 2: " << solve({7,12,1,0,16,2}, 30000000) << endl;

    return 0;
}