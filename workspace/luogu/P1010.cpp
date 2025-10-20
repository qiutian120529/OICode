#include<bits/extc++.h>
#define int long long
#define pii pair<int, int>
#define ld long double
using namespace std;
using namespace __gnu_pbds;

const int N = 0;

int n;

void check(int x){
  for(int i = 14; i >= 0; i--){
    if((1 << i) <= x){
      if(i == 1){
        cout << 2;
      }
      else if(i == 0){
        cout << "2(0)";
      }
      else{
        cout <<"2(";
        check(i);
        cout << ')';
      }
      x -= (1 << i);
      if(x != 0){
        cout << '+';
      }
    }
    }
}

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n;
  check(n);
  return 0;
}
