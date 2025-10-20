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

const int N = 20, M = 510;

int n, k, h[N], dp[M][N * M];

unordered_map<int, int> cnt1, cnt2;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> k;
  for(int i = 1, x; i <= n * k; i++){
    cin >> x;
    cnt1[x]++;
  }
  for(int i = 1, x; i <= n; i++){
    cin >> x;
    cnt2[x]++;
  }
  for(int i = 1; i <= k; i++){
    cin >> h[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n * k; j++){
      for(int x = 1; x <= min(j, k); x++){
        dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x]);
      }
    }
  }
  int ans = 0;
  for(const auto &[x, y] : cnt2){
    ans += dp[y][cnt1[x]];
  }
  cout << ans;
  return 0;
}
