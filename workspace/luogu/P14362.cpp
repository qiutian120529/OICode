#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e4 + 10;

int n, m, k, tot, fa[N], vis[N];
ll ans = LLONG_MAX;
int c[N], a[15][N];

struct Edge{
  int u, v, w;
};

vector<Edge> edge, et;

bool cmp(const Edge &a, const Edge &b){
  return a.w < b.w;
}

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void init(int x){
  tot = x;
  for(int i = 1; i <= n + k; i++){
    fa[i] = i;
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }
  sort(edge.begin(), edge.end(), cmp);
  init(n);
  for(const auto &[u, v, w] : edge){
    int FA = find(u), FB = find(v);
    if(FA != FB){
      tot--;
      fa[FA] = FB;
      et.push_back({u, v, w});
    }
    if(tot == 1) break;
  }
  edge = et;
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
      edge.push_back({n + i, j, a[i][j]});
    }
  }
  for(int st = 0; st < (1 << k); st++){
    int cnt = 0;
    ll sum = 0;
    for(int i = 1; i <= k; i++) vis[i] = 0;
    for(int i = 0; i < k; i++){
      if((st >> i) & 1){
        cnt++;
        sum += c[i + 1];
        vis[i + 1] = 1;
      }
    }
    init(n + cnt - 1);
    for(const auto &[u, v, w] : edge){
      int FA = find(u), FB = find(v);
      if(u > n && vis[u - n]) continue;
      if(FA != FB){
        sum += w;
        fa[FA] = FB;
        if(!(--tot)) break;
      }
    }
    if(!tot){
      ans = min(ans, sum);
    }
  }
  cout << ans;
  return 0;
}
