#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 10;
const ll inf = 3e11;

struct Edge{
  int v, l;
};

struct Node{
  int u;
  ll w;
  bool operator < (const Node &i) const {
    return w > i.w;
  }
};

int n, m, s, q, vis[N];
ll dis[N];
vector<Edge> g[N];

void dij(){
  priority_queue<Node> q;
  fill(vis + 1, vis + 1 + n, 0);
  fill(dis + 1, dis + 1 + n, inf);
  dis[s] = 0;
  q.push({s, 0});
  while(q.size()){
    auto [u, st] = q.top();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto [v, w] : g[u]){
      if(dis[u] + w < dis[v]){
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s >> q;
  for(int i = 1, u, v, l; i <= m; i++){
    cin >> u >> v >> l;
    g[u].push_back({v, l});
    g[v].push_back({u, l});
  }
  dij();
  while(q--){
    int h;
    cin >> h;
    cout << dis[h] << "\n";
  }
  return 0;
}
