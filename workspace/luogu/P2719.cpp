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

const int N = 1260;

int n;
double dp[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  n >>= 1;
  for(int i = 2; i <= n; i++){
    dp[i][0] = dp[0][i] = 1;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) * 0.5;
    }
  }
  cout << fixed << setprecision(4) << dp[n][n];
  return 0;
}
