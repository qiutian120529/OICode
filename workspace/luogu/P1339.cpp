#include<bits/stdc++.h>
using namespace std;

const int N = 2510, inf = 1e9;

int n, m, s, t, vis[N], dis[N];

struct Edge{
  int v, w;
};

struct P{
  int u, x;
  bool operator < (const P &i) const {
    return x > i.x;
  }
};

vector<Edge> g[N];

void dij();

int main(){
  cin >> n >> m >> s >> t;
  for(int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dij();
  cout << dis[t];
  return 0;
}

void dij(){
  priority_queue<P> q;
  fill(dis + 1, dis + 1 + n, inf);
  q.push({s, 0});
  dis[s] = 0;
  while(q.size()){
    auto [u, x] = q.top();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(const auto &[v, w] : g[u]){
      if(dis[u] + w < dis[v]){
        dis[v] = w + dis[u];
        q.push({v, dis[v]});
      }
    }
  }
}