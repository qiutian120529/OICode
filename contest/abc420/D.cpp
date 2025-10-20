#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 510;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, sx, sy, gx, gy;
char c[N][N];
bool f[N][N], door[N][N], open[N][N], vis[N][N][5];

struct P{
  int x, y;
  bool cnt;
  int dis;
};

queue<P> q;

void bfs();

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> c[i][j];
      if(c[i][j] == 'S'){
        sx = i, sy = j;
      }
      if(c[i][j] == 'G'){
        gx = i, gy = j;
      }
      if(c[i][j] == '?'){
        f[i][j] = 1;
      }
      if(c[i][j] == 'o'){
        door[i][j] = 1;
        open[i][j] = 1;
      }
      if(c[i][j] == 'x'){
        door[i][j] = 1;
        open[i][j] = 0;
      }
      if(c[i][j] == '#'){
        vis[i][j][0] = 1;
        vis[i][j][1] = 1;
      }
    }
  }
  bfs();
  cout << -1;
  return 0;
}

void bfs(){
  q.push({sx, sy, 0, 0});
  while(!q.empty()){
    int x = q.front().x, y = q.front().y, dist = q.front().dis;
    bool cnt = q.front().cnt;
    // cout << x << " " << y << "\n";
    q.pop();
    if(x < 1 || y < 1 || x > n || y > m || vis[x][y][cnt] || (door[x][y] == 1 && !(open[x][y] ^ cnt))) continue;
    vis[x][y][cnt] = 1;
    if(f[x][y]) cnt ^= 1;
    if(x == gx && y == gy){
      cout << dist << "\n";
      exit(0);
    }
    for(int i = 0; i < 4; i++){
      q.push({x + dx[i], y + dy[i], cnt, dist + 1});
    }
  }
}