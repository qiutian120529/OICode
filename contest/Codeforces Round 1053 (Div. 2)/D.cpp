#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int p = 998244353, N = 2e5 + 10, M = 2e5;

ll A[N], inv[N];

ll C(ll n, ll m){
  if(n < m) return 0;
  return A[n] * inv[m] % p * inv[n - m] % p;
}

int ksm(ll a, int b){
  long long sum = 1;
  while(b){
    if(b & 1){
      (sum *= a) %= p;
    }
    a = a * 1ll * a % p;
    b /= 2;
  }
  return sum;
}

void init(){
  A[0] = 1;
  for(int i = 1; i <= M; i++){
    A[i] = A[i - 1] * i % p;
  }
  inv[M] = ksm(A[M], p - 2);
  for(int i = M - 1; i >= 0; i--){
    inv[i] = inv[i + 1] * (i + 1) % p;
  }
}

void solve();

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  init();
  while(T--) solve();
  return 0;
}

ll n, sum, a[N], tag, cnt, ans;

void solve(){
  cin >> n;
  sum = 0, tag = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    sum += a[i];
    if(n + 1 == 2 * i && a[i] > 1) tag = 1;
    if(i > (n + 1) / 2 && a[i] != 0) tag = 1;
  }
  cnt = 2, ans = 1;
  if(tag || sum != n || a[1] < 2){
    cout << "0\n";
    return ;
  }
  if((n & 1) && a[n / 2 + 1] == 0) cnt++;
  for(int i = n / 2; i; i--){
    (ans *= C(cnt, a[i])) %= p;
    cnt += 2;
    cnt -= a[i];
  }
  cout << ans << "\n";
}