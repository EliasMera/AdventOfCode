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

int dirX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dirY[] = { 1, -1, 0, 0, 1, 1, -1, -1 };

int howMany(vector<string>& grid, int i, int j) {
  int ans = 0;
  for(int k = 0; k < 8; k++) {
    int newX = i + dirX[k];
    int newY = j + dirY[k];
    while(newX >= 0 && newX < grid.size()
    && newY >= 0 && newY < grid[0].size()
    && grid[newX][newY] == '.') {
      newX += dirX[k];
      newY += dirY[k];
    }

    if(newX >= 0 && newX < grid.size()
    && newY >= 0 && newY < grid[0].size()
    && grid[newX][newY] == '#') ans++;
  }
  return ans;
}

bool changed(vector<string>& old) {
  bool flag = false;
  vector<string> grid = old;
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++) {
      // rule 1
      int neighbors = howMany(old, i, j);
      if(grid[i][j] == 'L' && neighbors == 0) {
        flag = true;
        grid[i][j] = '#';
      } else if(grid[i][j] == '#' && neighbors >= 5) {
        flag = true;
        grid[i][j] = 'L';
      }
    }
  }
  
  old = grid;
  return flag;
}

int main() { _
  ifstream cn("day11.txt");
  string val;
  vector<string> vals;
  while(cn >> val) {
      vals.push_back(val);
  }

  while(changed(vals));
  
  int ans = 0;
  for(int i = 0; i < vals.size(); i++) {
    for(int j = 0; j < vals[0].size(); j++) {
      ans += vals[i][j] == '#';
    }
  }

  cout << ans << endl;

  return 0;
}
