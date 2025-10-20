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

const int N = 2e5 + 10;

int n, a[N];

void solve(){
  // vector<int> b;
  cin >> n;
  map<int, int> cnt;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    cnt[a[i]]++;
    // b.push_back(a[i]);
  }
  ll ans = 0, sum = 0;
  vector<ll> rec, even;
  for(auto e : cnt){
    ll key = e.first, val = e.second;
    sum += val / 2 * key;
    if(val & 1){
      rec.push_back(key);
    }
    else{
      even.push_back(key);
    }
    // if(ans + val / 2 * 2 * key - max(mx, key) <= max(mx, key)) continue;
    // ans += val / 2 * 2 * key;
    // edge += val / 2 * 2;
    // mx = max(mx, key);
  }
  if(sum == 0){
    cout << 0 << "\n";
    return ;
  }
  for(int x : rec){
    if(2 * sum > x){
      ans = max(ans, 2 * sum + x);
    }
  }
  for(int i = 1; i < rec.size(); i++){
    if(rec[i - 1] + 2 * sum > rec[i]){
      ans = max(ans, rec[i - 1] + 2 * sum + rec[i]);
    }
  }
  for(int x : even){
    if(sum > x){
      ans = max(ans, 2 * sum);
    }
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
