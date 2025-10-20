#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 2010;

int t, k, C[N][N], ans[N][N];

void init(){
  C[0][0] = 1;
  for(int i = 1; i <= 2000; i++){
    C[i][0] = 1;
    for(int j = 1; j <= 2000; j++){
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
      if(!C[i][j] && i >= j){
        ans[i][j]++;
      }
      ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> t >> k;
  init();
  while(t--){
    int n, m;
    cin >> n >> m;
    cout << ans[n][m] << "\n";
  }
  return 0;
}
