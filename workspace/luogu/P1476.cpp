#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3 + 10, inf = 1e9;

int n, m;
ll dis[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  n++;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) dis[i][j] = 0;
      else{
        dis[i][j] = inf;
      }
    }
  }
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    dis[u][v] = min(dis[u][v], -1ll * w);
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  cout << -dis[1][n] << "\n";
  for(int i = 1; i <= n; i++){
    if(dis[1][i] + dis[i][n] == dis[1][n]){
      cout << i << " ";
    }
  }
  return 0;
}
