#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 0;
int a, b, n;

void solve(){
  cin >> a >> b >> n;
  if(a + b == n || (a == b && 3 * a == n) || (a == n || b == n)){
    cout << "No\n";
  }
  else{
    cout << "Yes\n";
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
