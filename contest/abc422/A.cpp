#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 0;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int x, y;
  char c;
  cin >> x >> c >> y;
  cout << x + (y == 8) << "-" << y % 8 + 1;
  return 0;
}
