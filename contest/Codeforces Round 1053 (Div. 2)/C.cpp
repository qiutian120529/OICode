#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve();

signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}

const int N = 4e5 + 10;

int n, a[N], sum[N][3];

void solve(){
  cin >> n;
  for(int i = 1; i <= 2 * n; i++){
    sum[i][0] = sum[i][1] = 0;
  }
  for(int i = 1; i <= 2 * n; i++){
    cin >> a[i];
    sum[i][0] += sum[i - 1][0];
    sum[i][1] += sum[i - 1][1];
    sum[i][i & 1] += a[i] - a[i - 1];
  }
  int l = 1, r = 2 * n, ans = sum[r][0];
  cout << ans << " ";
  for(int i = 2; i <= n; i++){
    l++, r--;
    ans += 2 * (sum[r][!(i & 1)] - sum[l][!(i & 1)]);
    cout << ans << " ";
  }
  cout << "\n";
}