#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define int ll
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x);
using namespace std;

const int N = 210, M = 1e5 + 10;

int n, m, q, k, sz, a[M][N], task[M][N], c[M], rec[M], ans[M];

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n >> m >> q >> k;
  sz = k + 1;
  for(int i = 1; i <= k; i++){
    char ch;
    cin >> ch;
    if(ch == '1'){
      sz = __gcd(sz, i);
    }
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 1; i <= q; i++){
    for(int j = 1; j <= n; j++){
      cin >> task[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    memset(c, 0, sizeof c);
    memset(rec, 0, sizeof rec);
    for(int j = 1; j <= m; j++){
      c[a[j][i]]++;
      rec[0] += a[j][i];
    }
    for(int j = 1; j <= k; j++) c[j] += c[j - 1];
    for(int j = 1; j <= k; j++) rec[j] = rec[j - 1] - m + 2 * c[j - 1];
    for(int j = 1; j <= k; j++) rec[j % sz] = min(rec[j % sz], rec[j]);
    for(int j = 1; j <= q; j++) ans[j] += rec[task[j][i] % sz];
  }
  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
  return 0;
}   