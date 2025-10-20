#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 1e4 + 10;

int n, m;

vector<int> g[N], path;

void dfs(int u){
  for(int &v : g[u]){
    if(v){
      int vv = v;
      v = 0;
      dfs(vv);
    }
  }
  path.push_back(u);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v;
     cin >> u >> v;
     g[u].push_back(v);
     g[v].push_back(u);
  }
  dfs(1);
  reverse(path.begin(), path.end());
  for(int i : path){
    cout << i << "\n";
  }
  return 0;  
}
