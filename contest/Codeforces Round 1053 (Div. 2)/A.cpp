#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], b[N];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    cin >> a[i];
  }
  for(int i = 1; i < m; i++){
    if(a[i] >= a[i + 1]){
      cout << 1 << "\n";
      return ;
    }
  }
  for(int i = 1; i <= n; i++){
    if(i >= a[m]){
      cout << n - i + 1 << "\n";
      return ;
    }
  }
  cout << 1 << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}