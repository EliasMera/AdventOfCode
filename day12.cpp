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

int main() { _
  ifstream cn("day12.txt");
  string val;
  vector<string> vals;
  while(cn >> val) {
      vals.push_back(val);
  }

  int x = 0, y = 0;
  int wx = 10, wy = 1;
  int dir = 0;

  for(string s : vals) {
    char c = s[0];
    int val = stoi(s.substr(1));

    if(c == 'F') {
      if(dir == 0) x += val;
      else if(dir == 1) y += val;
      else if(dir == 2) x -= val;
      else if(dir == 3) y -= val;
    }
    else if(c == 'N') y -= val;
    else if(c == 'S') y += val;
    else if(c == 'W') x -= val;
    else if(c == 'E') x += val;
    else if(c == 'R') {
      val %= 360;
      if(val == 90) dir = (dir + 1) % 4;
      else if(val == 180) dir = (dir + 2) % 4;
      else if(val == 270) dir = (dir + 3) % 4;
    } else if(c == 'L') {
      val %= 360;
      val = 360 - val;
      if(val == 90) dir = (dir + 1) % 4;
      else if(val == 180) dir = (dir + 2) % 4;
      else if(val == 270) dir = (dir + 3) % 4;
    }
  }

  cout << "Part 1: ";
  cout << abs(x) + abs(y) << endl;
  x = y = 0;

  for(auto s : vals) {
    char c = s[0];
    int val = stoi(s.substr(1));
    if(c == 'F') {
      x += wx * val;
      y += wy * val;
    } else if(c == 'N') wy += val;
    else if(c == 'E') wx += val;
    else if(c == 'S') wy -= val;
    else if(c == 'W') wx -= val;
    else if(c == 'L') {
      while(val) {
        int tmp = wx;
        wx = -wy;
        wy = tmp;
        val -= 90;
      }
    } else if(c == 'R') {
      while(val) {
        int tmp = wx;
        wx = wy;
        wy = -tmp;
        val -= 90;
      }
    }
  }

  cout << "Part 2: ";
  cout << abs(x) + abs(y) << endl;

  return 0;
}