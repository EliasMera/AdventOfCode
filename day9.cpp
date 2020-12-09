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

int part2(vector<int> arr, int sum) { 
  int curr_sum, i, j; 
  int n = arr.size();

  for (i = 0; i < n; i++) { 
    curr_sum = arr[i]; 
    for (j = i + 1; j <= n; j++) { 
      if (curr_sum == sum) { 
        int mini = 1e9, maxi = 0;
        for(int k = i; k <= j - 1; k++) {
          mini = min(mini, arr[k]);
          maxi = max(maxi, arr[k]);
        }
        cout << mini + maxi << endl;
        return 1; 
      } 
      if (curr_sum > sum || j == n) 
        break; 
      curr_sum = curr_sum + arr[j];
    } 
  } 
  return 0; 
} 

int main() { _
  ifstream cn("day9.txt");

  vector<int> arr;
  int x;
  while(cn >> x) {
    arr.push_back(x);
  }

  int ans = 776203571;
  part2(arr, ans);
  return 0;
}
