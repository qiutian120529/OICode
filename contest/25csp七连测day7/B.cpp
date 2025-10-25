#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) do { \ 
  freopen((x ".in"), "r", stdin); \ 
} while(0)
#define FileOut(x) do { \
  freopen((x ".out"), "w", stdout); \ 
} while(0)
#define FileIO(x) do { \ 
  FileIn(x); FileOut(x); \
} while(0) 

using namespace std;

const int N = 4e3 + 10, p = 1e9 + 7;

ll n, a[N][N], b[N][N], suma[N], sumb[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  FileIO("mat");
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
      ll sum = 0;
      for(int k = 1; k <= n; k++){
        sum += a[i][k] * 1ll * b[k][j] % p;
        sum %= p;
      }
      ans = (ans ^ sum);
    }
  }
  cout << ans;
  return 0;
}
