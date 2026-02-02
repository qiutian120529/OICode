#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 10;

int n, k, p, now, ans, pos[N], sum[N], cnt[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> p;
  for(int i = 1; i <= n; i++){
    int a, b;
    cin >> b >> a;
    if(a <= p){
      now = i;
    }
    if(now >= pos[b]){
      sum[b] = cnt[b];
    }
    pos[b] = i;
    ans += sum[b];
    cnt[b]++;
  }
  cout << ans;
  return 0;
}
