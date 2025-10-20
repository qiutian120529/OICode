#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 3e5 + 10;

int n, m, c[N];
ll C[5010][5010];

void solve(){
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    sum += c[i];
  }
  ll ans = 1;
  for(int i = 1; i <= n; i++){
    ans = ans * C[sum][c[i]] % m;
    // int x = C[sum][c[i]];
    sum -= c[i];
    // cout << ans << ' ' << sum << " " << x << "\n";
  }
  // cout << "\n";
  cout << ans << "\n";
  // cout << "------------------\n";
}

void init(){
  C[0][0] = 1;
  for(int i = 1; i <= 5000; i++){
    C[i][0] = 1;
    for(int j = 1; j <= 5000; j++){
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
    }
  }
}

int main(){
  // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  int T;
  cin >> T >> m;
  init();
  while(T--) solve();
  return 0;
}
