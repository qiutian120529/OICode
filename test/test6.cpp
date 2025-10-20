#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) do { \ 
  freopen((x ".in"), "r", stdin); \ 
} while(0)
#define FileOut(x) do { \
  freopen((x ".out"), "w", stdout); \ 
} while(0)
#define FileIO(x) do { \ 
  FileIn(x); FileOut(x); \
} while(0) 

using namespace std;

const int N = 510;

int n, m, a[N], b[N], vis[N];

struct P{
  double t;
  int i, j;
  bool operator < (const P &i) const {
    return t > i.t;
  }
};

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  for(int i = 1; i <= n; i++) vis[i] = 0;
  vis[m] = 1;
  priority_queue<P> q;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(b[i] == b[j]){
        if(a[i] == a[j]){
          q.push({0, i, j});
        }
      }
      else{
        double t = (a[j] - a[i]) * 1.0 / (b[i] - b[j]);
        if(t >= 0){
          q.push({t, i, j});
        }
      }
    }
  }
  while(q.size()){
    auto [_, i, j] = q.top();
    q.pop();
    if(vis[i] && !vis[j]){
      vis[j] = 1;
    }
    else if(!vis[i] && vis[j]){
      vis[i] = 1;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) ans += vis[i];
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
