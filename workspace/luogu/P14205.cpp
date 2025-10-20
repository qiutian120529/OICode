#include<bits/stdc++.h>
#define pll pair<ll, ll>
#define ll long long
#define ld long double

using namespace std;

const int N = 0;

int n, s;

ll ans;

priority_queue<pll> q;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  for(int i = 1, a, k; i <= n; i++){
    cin >> a >> k;
    ans += a;
    if(a > k){
      q.push({k, a / k});
      a %= k;
    }
    if(a) q.push({a, 1});
  }
  while(s && q.size()){
    if(q.top().second <= s){
      s -= q.top().second;
      ans -= q.top().second * q.top().first;
      q.pop();
      continue;
    }
    ans -= s * q.top().first;
    break;
  }
  cout << ans;
  return 0;
}
