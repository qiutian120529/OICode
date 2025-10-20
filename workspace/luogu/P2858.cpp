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

const int N = 2010;
int n, a[N], b[N];
long long ans, dp[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  memset(dp, 0xcf, sizeof(dp));
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  dp[1][n] = 0;
  for(int l = n; l >= 2; l--){
    for(int i = 1; i + l - 1 <= n; i++){
      int j = i + l - 1;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i] + b[i] * (n - l));
      dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + a[j] + b[j] * (n - l));
    }
  }
  for(int i = 1; i <= n; i++){
    ans = max(ans, 1ll * dp[i][i] + a[i] + b[i] * (n - 1));
  }
  cout << ans;
  return 0;
}
