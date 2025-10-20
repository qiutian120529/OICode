#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define int long long
#define ld long double

using namespace std;

const int N = 2e5 + 10;

int n, k;
ll a[N], dp[N];

struct Tree{
  int c[N * 2 + 100];
  void add(int x, int v){
    for(; x; x -= -x & x) c[x] = max(c[x], v);
  }

  
  int query(int x, int p){
    int res = -1e9;
    for(; x < p; x += -x & x) res = max(res, c[x]);
    return res;
  }

  void renew(int x, int p){
    int y = x;
    for(; x < p; x += -x & x) c[x] = -1e9;
    x = y;
    for(; x; x -= -x & x) c[x] = -1e9;
  }
}T;

vector<ll> rec;

int gt(int x){
  return lower_bound(rec.begin(), rec.end(), x) - rec.begin()+1;
}

bool check(int mid){
  rec.clear();
  for(int i = 1; i <= n; i++){
    rec.push_back(a[i]);
    rec.push_back(a[i] - mid);
  }
  rec.push_back(0);
  sort(rec.begin(), rec.end());
  rec.erase(unique(rec.begin(), rec.end()), rec.end());
  for(int i = 1; i <= rec.size(); i++){
    T.renew(i, rec.size());
  }
  dp[0] = 0;
  T.add(gt(0), dp[0]);
  for(int i = 1; i <= n; i++){
    dp[i] = T.query(gt(a[i] - mid), rec.size() + 1) + 1;
    T.add(gt(a[i]), dp[i]);
    if(dp[i] >= k) return 1;
  }
  return 0;
}

void solve(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    a[i] += a[i - 1];
  }
  ll l = -1e15, r = 1e15, ans = r;
  while(l <= r){
    ll mid = l + r >>1;
    if(check(mid)){
      r = mid - 1;
      ans = mid;
    }
    else{
      l = mid + 1;
    }
  }
  cout << ans << "\n";
}

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
