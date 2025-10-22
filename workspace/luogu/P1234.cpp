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

const int N = 1010;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, vis[N][N];
char c[N][N];
string comp = "hehe";

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> c[i][j];
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){  
    for(int j = 1; j <= m; j++){
      for(int dir = 0; dir < 4; dir++){
        int x = i, y = j, k = 0;
        for(; k < 4; k++){
          if(x < 0 || y < 0 || x > n || y > m || comp[k] != c[x][y]){
            break;
          }
          x += dx[dir], y += dy[dir];
        }
        if(k == 4){
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
