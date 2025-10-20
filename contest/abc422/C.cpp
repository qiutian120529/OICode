#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 0;

void solve(){
  ll na, nb, nc;
  cin >> na >> nb >> nc;
  ll mn = min({na, nb, nc});
  ll ans = mn;
  na -= mn, nb -= mn, nc -= mn;
  if(min(na, nc / 2) > min(na / 2, nc)){
    mn = min(na, nc / 2);
    ans += mn;
    na -= mn, nc -= 2 * mn;
  }
  else{
    mn = min(na / 2, nc);
    ans += mn;
    na -= mn * 2, nc -= mn;
  }
  if(min(na, nc / 2) > min(na / 2, nc)){
    mn = min(na, nc / 2);
    ans += mn;
    na -= mn, nc -= 2 * mn;
  }
  else{
    mn = min(na / 2, nc);
    ans += mn;
    na -= mn * 2, nc -= mn;
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int T;
  cin >> T;
  while(T--) solve();;
  return 0;
}
