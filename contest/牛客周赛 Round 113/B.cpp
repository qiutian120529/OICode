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

const int N = 2e5 + 10, p = 1e9 + 7;

ll n, a[N], b[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
  }
  ll x = a[1], y = b[1];
  for(int i = 2; i <= n; i++){
    ll xx = x, yy = y;
    x = ((xx * a[i] % p + p) % p + p + p - (yy * b[i] % p + p) % p) % p;
    y = ((xx * b[i] % p + p) % p + p + p + (yy * a[i] % p + p) % p) % p;
  }
  cout << (ll)x << " " << (ll)y;
  return 0;
}
