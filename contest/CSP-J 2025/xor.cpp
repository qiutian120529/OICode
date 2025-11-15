#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;

int n, k, a[N], pre[N], dp[N];
unordered_map<int, int> rec;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  rec[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pre[i] = (pre[i - 1] ^ a[i]);
  }
  for(int i = 1; i <= n; i++){
    dp[i] = dp[i - 1];
    if(rec.count(k ^ pre[i])){
      dp[i] = max(dp[i - 1], rec[k ^ pre[i]] + 1);
    }
    rec[pre[i]] = max(rec[pre[i]], dp[i]);
  }
  cout << dp[n];
  return 0;
}
