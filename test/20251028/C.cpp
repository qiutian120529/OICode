#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], b[N];
ll ans, pre[N], k;

unordered_map<ll, ll> dp;

void dfs(int x, ll cost, ll sum){
  if(x == n + 1){
    if(cost <= m) ans = max(ans, sum);
    return ;
  }
  dfs(x + 1, cost ^ a[x], sum + b[x]);
  dfs(x + 1, cost, sum);
}

struct P{
  int a, b;
  bool operator < (const P &i) const {
    return b < i.b;
  }
}rec[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  if(m <= 100){
    unordered_map<ll, ll> f;
    for(int st = 0; st < (1 << (n / 2)); st++){ 
      ll cost = 0, sum = 0;
      for(int j = 0; j < n / 2; j++){//1~n/2
        if((st >> j) & 1){
          cost ^= a[j + 1];
          sum += b[j + 1];
        }
      }
      f[cost] = max(f[cost], sum);
    }
    for(int st = 0; st < (1 << (n - n / 2)); st++){ // n - n / 2 ~ n
      ll cost = 0, sum = 0;
      for(int j = 0; j < (n - n / 2); j++){ // n = 3, n / 2 = 1, n - n / 2 = 2
        if ((st >> j) & 1) {
          cost ^= a[n / 2 + j + 1];
          sum += b[n / 2 + j + 1];
        }
      }
      for(int i = 0; i <= 127; i++){
        if((cost ^ i) <= m && f.count(i)){
          ans = max(ans, sum + f[i]);
        }
      }
    }
    cout << ans;
  }
  else if(n <= 20){
    dfs(1, 0, 0);
    cout << ans;
  }
  return 0;
}
