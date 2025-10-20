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

const int N = 1510;
int n, cost[N][N], sum[N][N];
bool c[N][N];
char ch;

void solve(int day){
  int x = n, y = n;
  if(day != 0){
    cin >> x >> y;
    c[x][y] ^= 1;
  }
  for(int i = x; i >= 1; i--){
    for(int j = y; j >= 1; j--){
      if(c[i][j]){
        cost[i][j] = cost[i][j + 1];
      }
      else{
        cost[i][j] = cost[i + 1][j];
      }
      sum[i][j] = cost[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1];
    }
  }
  cout << sum[1][1] << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> ch;
      c[i][j] = (ch == 'R');
    }
    cin >> cost[i][n + 1];
  }
  for(int i = 1; i <= n; i++){
    cin >> cost[n + 1][i];
  }
  int T;
  cin >> T;
  for(int i = 0; i <= T; i++) solve(i);
  return 0;
}

/*
#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define int long long
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

const int N = 1510;
int n, cost[N][N], sum[N][N];
int ans;
bool c[N][N];
char ch;

// void solve(int day){
//   int x = n, y = n;
//   if(day != 0){
//     cin >> x >> y;
//     c[x][y] ^= 1;
//   }
//   for(int i = x; i >= 1; i--){
//     for(int j = y; j >= 1; j--){
//       if(c[i][j]){
//         cost[i][j] = cost[i][j + 1];
//       }
//       else{
//         cost[i][j] = cost[i + 1][j];
//       }
//       sum[i][j] = cost[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1];
//     }
//   }
//   cout << sum[1][1] << "\n";
// }

void dfs(int x, int y, int spt){
  if(!x || !y) return;
  cost[x][y] = spt;
  ans += spt;
  if(!c[x - 1][y]){
    dfs(x - 1, y, spt);
  }
  if(c[x][y - 1]){
    dfs(x, y - 1, spt);
  }
}

void work(int x, int y, int spt){
  if(!x || !y) return ;
  ans -= cost[x][y] + spt;
  cost[x][y] = spt;
  if(!c[x - 1][y]){
    work(x - 1, y, spt);
  }
  if(c[x][y - 1]){
    work(x, y - 1, spt);
  }
}

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> ch;
      c[i][j] = (ch == 'R');
    }
    cin >> cost[i][n + 1];
  }
  for(int i = 1; i <= n; i++){
    cin >> cost[n + 1][i];
  }
  for(int i = 1; i <= n; i++){
    if(c[i][n]){
      dfs(i, n, cost[i][n + 1]);
    }
    if(!c[n][i]){
      dfs(n, i, cost[n + 1][i]);
    }
  }
  int T;
  cin >> T;
  cout << ans << "\n";
  // for(int i = 0; i <= T; i++) solve(i);
  while(T--){
    int x, y;
    cin >> x >> y;
    c[x][y] ^= 1;
    ans -= cost[x][y];
    if(!c[x][y]) cost[x][y] = cost[x + 1][y];
    else cost[x][y] = cost[x][y + 1];
    ans += cost[x][y];
    work(x, y, cost[x][y]);
    cout << ans << "\n";
    // solve();
  }
  return 0;
}
*/