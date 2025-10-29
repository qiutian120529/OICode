#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, m, L, V;

int d[N], v[N], a[N], p[N], vis[N];

struct node {
	int ql, qr;
	bool operator < (const node &i) const {
    if(ql != i.ql) return ql < i.ql;
    return qr > i.qr;
  }
};

vector<node> s;

void solve(){
  s.clear();  
  cin >> n >> m >> L >> V;
  for(int i = 1; i <= n; i++){
    cin >> d[i] >> v[i] >> a[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> p[i];
  }
  for(int i = 1; i <= n; i++){
    if(a[i] <= 0 && v[i] <= V){
      continue;
    }
    if(a[i] > 0){
      int tar = (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
      if(v[i] > V){
        tar = d[i] - 1;
      }
      int l = 1, r = m, res = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(p[mid] > tar){
          r = mid - 1;
          res = mid;
        }
        else{
          l = mid + 1;
        }
      }
      if(!res){
        continue;
      }
      s.push_back({res, m});
    }
    else{
      int l = 1, r = m, pos = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(p[mid] >= d[i]){
          r = mid - 1;
          pos = mid;
        }
        else{
          l = mid + 1;
        }
      }
      if(!pos) continue;
      l = pos, r = m;
      int res = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        double u = sqrt(v[i] * v[i] * 1.0 + 2.0 * a[i] * (p[mid] - d[i]));
        if(u > V){
          l = mid + 1;
          res = mid;
        }
        else{
          r = mid - 1;
        }
      }
      if(res < pos) continue;
      s.push_back({pos, res});
    }
  }
  sort(s.begin(), s.end());
  int mn = 1e9;
  for(int i = s.size() - 1; i >= 0; i--){
    if(mn <= s[i].qr){
      vis[i] = 1;
    }
    mn = min(mn, s[i].qr);
  }
  int ans = 0, pre = 0;
  for(int i = 0; i < s.size(); i++){
    const auto &[ql, qr] = s[i];
    if(vis[i]) vis[i] = 0;
    else if(pre < ql){
      ans++, pre = qr;
    }
  }
  cout << s.size() << " " << m - ans << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
