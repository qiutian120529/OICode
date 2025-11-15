#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e3 + 10, p = 998244353;

int n, a[N];
ll fac[N], inv[N];

ll ksm(ll a, int b){
  ll sum = 1;
  while(b){
    if(b & 1){
      sum = sum * a % p;
    }
    a = a * a % p;
    b /= 2;
  }
  return sum;
}

ll C(int n, int m){
  return fac[n] * inv[m] % p * inv[n - m] % p;
}

ll ans = 0;

void dfs(int x, int sum, int cnt){
  if(x == n + 1){
    return ;
  }
  if(sum > a[x] && cnt >= 2){
    ans = (ans + 1) % p;
  }
  dfs(x + 1, sum, cnt);
  dfs(x + 1, sum + a[x], cnt + 1);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    sum += a[i];
  }
  if(sum == n){
    fac[1] = 1;
    for(int i = 2; i <= n; i++){
      fac[i] = fac[i - 1] * i;
    }
    inv[n] = ksm(fac[n], p - 2);
    for(int i = n - 1; i >= 1; i--){
      inv[i] = inv[i + 1] * (i + 1);
    }
    for(int i = 3; i <= n; i++){
      ans = (ans + C(n, i)) % p;
    }
    cout << ans;
    return 0;
  }
  sort(a + 1, a + 1 + n);
  dfs(1, 0, 0);
  cout << ans;
  return 0;
}
