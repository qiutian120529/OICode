#include<bits/stdc++.h>
#define ll long long

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
  while(q--){
    ll x;
    cin >> x;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(i == j) continue;
        ans = max(ans, 1ll * k[j] * (k[i] * x + b[i]) + b[j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
