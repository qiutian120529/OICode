#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e3 + 10;

struct Edge{
  int v;
  long double w;
};

struct Node{
  int x;
  long double dis;
  bool operator < (const Node &i) const {
    return dis < i.dis;
  }
};

vector<Edge> g[N];

int n, m, s, t;
long double dis[N];
bool vis[N];

void dij(){
  fill(dis + 1, dis + 1 + n, 0);
  fill(vis + 1, vis + 1 + n, 0);
  priority_queue<Node> q;
  q.push({s, 1});
  dis[s] = 1;
  while(q.size()){
    auto [u, mis] = q.top();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(const auto &[v, w] : g[u]){
      if(!vis[v] && mis * w > dis[v]){
        dis[v] = mis * w;
        q.push({v, dis[v]});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    g[u].push_back({v, (100 - w) / 100.0});
    g[v].push_back({u, (100 - w) / 100.0});
  }
  cin >> s >> t;
  dij();
  cout << fixed << setprecision(8) << 100.0 / dis[t];
  return 0;
}
