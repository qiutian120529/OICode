#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3 + 10;

struct edge{
  int u, v, w;
  bool operator < (const edge &i) const{
    return w > i.w;
  }
};

int n, m;
vector<edge> g;
int fa[N];

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
  // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) fa[i] = i;
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    g.push_back({u, v, w});
  }
  sort(g.begin(), g.end());
  int test = 0, sum = 0, cnt = n;
    // fa[4] = 5;
    // fa[2] = 3;
  // cout << find(2) << "*****" << endl;
  for(auto [u, v, w] : g){
    // cout << ++test << " " << u << " " << v << " " << w << "\n";
    int Fu = find(u), Fv = find(v);
    // cout << "---------\n";
    if(Fu == Fv) continue;
    cnt--;
    fa[Fu] = Fv;
    sum += w;
  }
  if(cnt != 1) cout << -1;
  else cout << sum;
  return 0;
}
