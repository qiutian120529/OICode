#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}

const int N = 1e5 + 10;

int n, m, a[N];
string s;

void solve(){
  vector<int> ans;
  map<int, bool> f; 
  cin >> n >> m;
  cin >> s;
  s = '#' + s;
  for(int i = 1; i <= m; i++){
    cin >> a[i];
    ans.push_back(a[i]);
    f[a[i]] = 1;
  }
  int x = 1;
  for(int i = 1; i <= n; i++){
    char ch = s[i];
    if(ch == 'A'){
      x = x + 1;
      ans.push_back(x);
    }
    else{
      while(f[++x]);
      ans.push_back(x);
      while(f[++x]);
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << "\n";
  for(int i : ans){
    cout << i << " ";
  }
  cout << "\n";
}