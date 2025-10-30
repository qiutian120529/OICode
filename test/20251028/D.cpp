#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll> 

using namespace std;

const int N = 1e5 + 10;

ll n, k[N], b[N], q;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> k[i] >> b[i];
  }
  cin >> q;
  for(int i = 1; i <= q; i++){
    ll x;
    cin >> x;
    vector<pii> c;
    for(int j = 1; j <= n; j++){
      c.push_back({k[j] * x + b[j], j});
    }
    sort(c.begin(), c.end());
    ll ans = 0;
    for(int j = 1; j <= n; j++){
      if(j != c[0].second){
        ans = max(ans, k[j] * c[0].first + b[j]);
      }
      if(j != c[1].second){
        ans = max(ans, k[j] * c[1].first + b[j]);
      }
      if(j != c[c.size() - 1].second){
        ans = max(ans, k[j] * c[c.size() - 1].first + b[j]);
      }
      if(j != c[c.size() - 2].second){
        ans = max(ans, k[j] * c[c.size() - 2].first + b[j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
