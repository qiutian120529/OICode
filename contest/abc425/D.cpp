#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 0;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int h, w;
vector<vector<char> > s;
vector<vector<int> > vis;
vector<vector<int> > cnt;

queue<pii> q;
queue<pii> rec;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> h >> w;
  s.assign(h + 5, vector<char> (w + 5));
  vis.assign(h + 5, vector<int> (w + 5, 0));
  cnt.assign(h + 5, vector<int> (w + 5, 0));
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> s[i][j];
      if(s[i][j] == '#'){
        q.push({i, j});
        cnt[i][j] = 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
          cnt[i + dx[k]][j + dy[k]]++;
        }
      }
    }
  }
  int ans = 0;
  while(!q.empty()){
    while(!q.empty()){
      int x = q.front().first, y = q.front().second;
      q.pop();
      ans++;
      for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > h || ny > w || vis[nx][ny] || cnt[nx][ny] != 1) continue;
        vis[nx][ny] = 1;
        rec.push({nx, ny});
      }
    }
    q = rec;
    while(!rec.empty()){
      int x = rec.front().first, y = rec.front().second;
      rec.pop();
      for(int i = 0; i < 4; i++){
        cnt[x + dx[i]][y + dy[i]]++;
      }
    }
  }
  cout << ans;
  return 0;
}
