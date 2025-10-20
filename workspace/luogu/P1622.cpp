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

const int N = 110, inf = 2e9;

int n, m, a[N], dp[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> m >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  a[0] = 0, a[n + 1] = m + 1;
  for(int len = 1; len <= n; len++){
    for(int l = 1, r = l + len - 1; l <= n && r <= n; l++, r++){
      dp[l][r] = inf;
      for(int k = l; k <= r; k++){
        dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + a[r + 1] - 1 - a[l - 1] - 1);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}
