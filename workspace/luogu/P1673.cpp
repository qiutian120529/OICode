#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e4 + 10, inf = 2e7;

int n, k;
vector<int> g[N];
int dis[N], vis[N];

void bfs(){
  fill(dis + 1, dis + 1 + k, inf);
  queue<int> q;
  q.push(1);
  dis[1] = 0;
  while(q.size()){
    int u = q.front();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(int v : g[u]){
      if(dis[v] > dis[u] + 1){
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for(int i = 1, u, v; i <= n; i++){
    cin >> u >> v;
    g[u].push_back(v);
  }
  bfs();
  // for(int i = 1; i <= k; i++) cout << dis[i] << " ";
  // cout << "\n";
  cout << (dis[k] == inf ? -1 : dis[k] + 1);
  return 0;
}
