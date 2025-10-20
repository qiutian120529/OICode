#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 2e5 + 10;

ll n, q, a[N], b[N], ans, mn[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++){
    mn[i] = min(a[i], b[i]);
    ans += mn[i];                 
  }
  // cout << ans << "*\n";
  while(q--){
    ll x, v;
    char c;
    cin >> c >> x >> v;
    ans -= mn[x];
    if(c == 'A'){
      a[x] = v;
    }
    else{
      b[x] = v;
    }
    ans += (mn[x] = min(a[x], b[x]));
    cout << ans << "\n";
  }
  return 0;
}
