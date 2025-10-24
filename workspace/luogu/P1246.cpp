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

const int N = 10, M = 30;

int dp[M][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  string s;
  cin >> s;
  for(int i = 1; i < s.size(); i++){
    if(s[i - 1] >= s[i]){
      cout << 0;
      return 0;
    }
  }
  for(int i = 1; i <= 26; i++){
    dp[i][1] = 1;
  }
  for(int i = 2; i <= 6; i++){
    for(int j = 26 - i + 1; j; j--){
      dp[j][i] = dp[j + 1][i - 1] + dp[j + 1][i];
    }
  }
  int ans = 0, cnt = 0;
  for(int i = s.size() - 1; i >= 0; i--){
    cnt++;
    for(int j = 1; j <= s[i] - 'a' + 1; j++){
      ans += dp[j][cnt];
    }
  }
  cout << ans;
  return 0;
}
