#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 810;

int n, m, x[N], y[N];


int fa[N];

struct P{
  int u, v;
  double w;
};

vector<P> edge;

bool cmp(const P &a, const P &b){
  return a.w < b.w;
}

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  const int l = m + 1, r = m + 2;
  for(int i = 1; i <= m + 2; i++) fa[i] = i;
  for(int i = 1; i <= m; i++){
    cin >> x[i] >> y[i];
    for(int j = 1; j < i; j++){
      double step = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) / 2.0;
      edge.push_back({i, j, step});
    }
    edge.push_back({l, i, (double) x[i]});
    edge.push_back({r, i, (double) n - x[i]});
  }
  sort(edge.begin(), edge.end(), cmp);
  for(auto [u, v, w] : edge){
    int FA = find(u), FB = find(v);
    if(FA != FB){
      fa[FA] = FB;
    }
    if(find(l) == find(r)){
      cout << fixed << setprecision(2);
      cout << w << "\n";
      return 0;
    }
  }
  return 0;
}
