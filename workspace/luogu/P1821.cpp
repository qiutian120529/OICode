#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10, inf = 1e9;

int n, m, s, vis[N], dis[N], sum[N];

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

void dij(int p){
  priority_queue<P> q;
  fill(dis + 1, dis + 1 + n, inf);
  fill(vis + 1, vis + 1 + n, 0);
  q.push({s, 0});
  dis[s] = 0;
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

int main(){
  cin >> n >> m >> s;
  for(int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    g[v][0].push_back({u, w});
    g[u][1].push_back({v, w});
  }
  dij(0);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    sum[i] = dis[i];
  }
  // cout << ans << " ";
  dij(1);
  for(int i = 1; i <= n; i++){
    if(dis[i] != inf && sum[i] != inf) ans = max(ans, sum[i] + dis[i]);
  }
  cout << ans;
  return 0;
}