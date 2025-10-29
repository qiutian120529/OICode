#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10, inf = 1e9;
ll n, a[N], dp[N], sum[N];

void solve() {
  cin >> n;
  unordered_map<ll, ll> lst;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i] * (a[i] == a[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if(lst.count(a[i])){
      dp[i] = max(dp[i], dp[lst[a[i]] + 1] + a[i] + sum[i] - sum[lst[a[i]] + 1]);
    }
    lst[a[i]] = i;
  }
  cout << dp[n] << "\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}