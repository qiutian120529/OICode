#include<bits/stdc++.h>
#define pii pair<long long, long long>
#define ll long long
#define ld long double
#define int long long
using namespace std;

const int N = 510, p1 = 1e9 + 9, p2 = 998244353, p = 1e9 + 7, base1 = 131, base2 = 13331;

int n;
long long a[N], b1[N], b2[N];

struct P{
  int w, x, y, z;
};

void solve(){
  long long ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  map<pii, long long> cnt;
  for(int i = 1; i <= n; i++){
    stack<int> st;
    for(int j = i; j <= n; j++){
      if(!st.empty() && a[st.top()] == a[j]){
        st.pop();
        if(!st.empty()){
          b1[j] = b1[st.top()];
          b2[j] = b2[st.top()];
        }
        else{
          b1[j] = b2[j] = 0;
        }
      }
      else{
        if(!st.empty()){
          b1[j] = (b1[st.top()] * base1 + a[j]) % p1;
          b2[j] = (b2[st.top()] * base2 + a[j]) % p2;
        }
        else{
          b1[j] = a[j];
          b2[j] = a[j];
        }
        st.push(j);
      }
      cnt[{b1[j], b2[j]}]++;
    }
  }
  for(auto it : cnt){
    long long y = it.second;
    ans += y * y % p;
    ans %= p;
  }
  cout << ans << '\n';
}

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // freopen("game.in", "r", stdin);
  // freopen("game.out", "w", stdout);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}