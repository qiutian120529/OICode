#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;

int n, m, s, tot, dfn[N], f[20][N];

vector<int> g[N];

void dfs(int u, int fa){
  dfn[u] = ++tot;
  f[0][dfn[u]] = fa;
  for(int v : g[u]){
    if(v == fa) continue;
    dfs(v, u);
  }
}

int work(int x, int y){
  return dfn[x] < dfn[y] ? x : y;
}

int lca(int u, int v){
  if(u == v) return u;
  u = dfn[u], v = dfn[v];
  if(u > v) swap(u, v);
  int d = __lg(v - u);
  u++;
  return work(f[d][u], f[d][v - (1 << d) + 1]);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(s, 0);
  for(int i = 1; i <= __lg(n); i++){
    for(int j = 1; j + (1 << i - 1) <= n; j++){
      f[i][j] = work(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
    }
  }
  for(int i = 1, u, v; i <= m; i++){
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }
  return 0;
}
