#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 0;

ll x;
vector<ll> ans;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> x;
  for(ll i = ceil(-sqrtl(2 * abs(x) + 1)) - 1; ; i++){
    if(i > 0 && i * i > 2 * abs(x) + 1) break;
    if((x - i * i) % (2 * i - 1) == 0){
      ans.push_back((x - i * i) / (2 * i - 1));
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << "\n";
  for(ll i : ans) cout << i << " ";
  return 0;
}
