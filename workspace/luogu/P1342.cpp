#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10, inf = 1e9;

int n, m, vis[N], dis[N];

struct Edge{
  int v, w;
};

struct P{
  int u, x;
  bool operator < (const P &i) const {
    return x > i.x;
  }
};

vector<Edge> g[N][2];

void dij(int p);

int main(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    g[v][0].push_back({u, w});
    g[u][1].push_back({v, w});
  }
  dij(0);
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    ans += dis[i];
  }
  // cout << ans << " ";
  dij(1);
  for(int i = 1; i <= n; i++){
    ans += dis[i];
  }
  cout << ans;
  return 0;
}

void dij(int p){
  priority_queue<P> q;
  fill(dis + 1, dis + 1 + n, inf);
  fill(vis + 1, vis + 1 + n, 0);
  q.push({1, 0});
  dis[1] = 0;
  while(q.size()){
    auto [u, x] = q.top();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(const auto &[v, w] : g[u][p]){
      if(dis[u] + w < dis[v]){
        dis[v] = w + dis[u];
        q.push({v, dis[v]});
      }
    }
  }
}