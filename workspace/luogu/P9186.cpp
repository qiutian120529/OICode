#include<bits/extc++.h>
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
using namespace __gnu_pbds;

const int N = 1.5e5 + 10;

// struct P{
//   int x, id;
//   bool operator < (const P &i) const{
//     if(x != i.x) return x < i.x;
//     return id < i.id;
//   }
// }a[N];

ll n, a[N], b[N];
ll sum[N], tot;

// bool cmp(const P &a, const P &b){
//   if(a.x != b.x){
//     return a.x < b.x;
//   }
//   return a.id < b.id;
// }

gp_hash_table<ll, ll> rec;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for(int i = 1; i <= n; i++){
    tot += i * b[i], sum[i] = sum[i - 1] + b[i], rec[b[i]] = i;
  }
  ll q;
  cin >> q;
  while(q--){
    ll x, y;
    cin >> x >> y;
    ll p = upper_bound(b + 1, b + 1 + n, y) - b;
    ll ans = tot - rec[a[x]] * a[x] + sum[rec[a[x]]] - sum[p - 1];
    if(p > rec[a[x]]) ans += (p - 1) * y;
    else ans += p * y - b[rec[a[x]]];
    cout << ans << "\n";
  }
  return 0;
}
