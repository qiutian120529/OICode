#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 110;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, book[N][N], vis[N][N], dis[N][N];
int sx, sy, fx, fy;

struct P{
  int pre, x, y, step; 
};

void bfs(){
  queue<P> q;
  memset(dis, 0x3f, sizeof dis);
  q.push({0, sx, sy, 0});
  while(q.size()){
    auto [pre, x, y, step] = q.front();
    q.pop();
    if(x < 1 || y < 1 || x > n || y > n || (book[x][y] != 0 && book[x][y] == pre) || vis[x][y]){
      continue;
    }
    dis[x][y] = min(dis[x][y], step);
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
      q.push({book[x][y], x + dx[i], y + dy[i], step + 1});
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char ch;
      cin >> ch;
      if(ch == 'A'){
        sx = i, sy = j;
      }
      if(ch == 'B'){
        fx = i, fy = j;
      }
      if(ch == '+'){
        book[i][j] = 1;
      }
      if(ch == '-'){
        book[i][j] = -1;
      }
    }
  }
  bfs();
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= n; j++){
  //     cout << dis[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << dis[fx][fy];
  return 0;
}
