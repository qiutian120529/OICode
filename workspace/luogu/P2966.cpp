#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e4 + 10, inf = 1e9;

struct node{
  int v, id;
}c[N];

bool cmp(const node &a, const node &b){
  return a.v < b.v;
}

int n, m, q;
int ans[N][N], dis[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++){
    cin >> c[i].v;
    c[i].id = i;
  }
  sort(c + 1, c + 1 + n, cmp);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i != j) dis[i][j] = inf;
      ans[i][j] = inf;
    }
  }
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    dis[u][v] = min(dis[u][v], w);
    dis[v][u] = min(dis[v][u], w);
  }
  for(int z = 1; z <= n; z++){
    for(int x = 1; x <= n; x++){
      for(int y = 1; y <= n; y++){
        int i = c[x].id, j = c[y].id, k = c[z].id;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        ans[i][j] = min(ans[i][j], dis[i][j] + max({c[x].v, c[y].v, c[z].v}));
      }
    }
  }
  while(q--){
    int s, t;
    cin >> s >> t;
    cout << ans[s][t] << "\n";
  }
  return 0;
}
