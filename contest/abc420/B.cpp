#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 110;

int n, m, ans[N];
char c[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> c[i][j];
    }
  }
  for(int j = 1; j <= m; j++){
    int x = 0, y = 0;
    for(int i = 1; i <= n; i++){
      if(c[i][j] == '0') x++;
      if(c[i][j] == '1') y++;
    }
    if(x == 0 || y == 0){
      for(int i = 1; i <= n; i++){
        ans[i]++;
      }
    }
    else if(x < y){
      for(int i = 1; i <= n; i++){
        if(c[i][j] == '0') ans[i]++;
      }
    }
    else{
      for(int i = 1; i <= n; i++){
        if(c[i][j] == '1') ans[i]++;
      }
    }
  }
  int mx = 0;
  for(int i = 1; i <= n; i++){
    mx = max(mx, ans[i]);
    // cout << ans[i] << " ";
  }
  for(int i = 1; i <= n; i++){
    if(ans[i] == mx){
      cout << i << " ";
    }
  }
  return 0;
}
