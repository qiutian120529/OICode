#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double

using namespace std;

const int N = 4e3 + 10, p = 1e9 + 7;

int n, a[N][N], b[N][N];
ll c[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = n; i; i--){
    cin >> a[1][i];
    for(int x = 1, y = i; x <= n && y <= n; x++, y++){
      a[x][y] = a[1][i];
    }
  }
  for(int i = 2; i <= n; i++){
    cin >> a[i][1];
    for(int x = i, y = 1; x <= n && y <= n; x++, y++){
      a[x][y] = a[i][1];
    }
  }
  for(int i = n; i; i--){
    cin >> b[1][i];
    for(int x = 1, y = i; x <= n && y <= n; x++, y++){
      b[x][y] = b[1][i];
    }
  }
  for(int i = 2; i <= n; i++){
    cin >> b[i][1];
    for(int x = i, y = 1; x <= n && y <= n; x++, y++){
      b[x][y] = b[i][1];
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      c[i][1] = (c[i][1] % p + (a[i][j] % p) * 1ll * (b[j][1] % p) % p) % p;
    }
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= n; j++){
      c[1][i] = (c[1][i] % p + (a[1][j] % p) * 1ll * (b[j][i] % p) % p) % p;
    }
  }
  for(int i = 2; i <= n; i++){
    for(int j = 2; j <= n; j++){
      c[i][j] = (c[i - 1][j - 1] - a[i - 1][n] * 1ll * b[n][j - 1] % p + a[i][1] * 1ll * b[1][j] % p + p) % p;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      ans = (ans ^ c[i][j]);
    }
  }
  cout << ans;
  return 0;
}
