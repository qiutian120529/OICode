#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 2e5 + 10;

int n, q, a[N], cnt;
ll b[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }
  while(q--){
    int opt, c, l, r;
    cin >> opt;
    if(opt == 1){
      cin >> c;
      cnt += c;
      cnt %= n;
    }
    else{
      cin >> l >> r;
      if(r + cnt > n){
        if(l + cnt > n){
          cout << b[r + cnt - n] - b[l + cnt - n - 1];
        }
        else{
          cout << b[n] + b[r + cnt - n] - b[l + cnt - 1];
        }
      }
      else{
        cout << b[r + cnt] - b[l + cnt - 1];
      }
      cout << "\n";
    }
  }
  return 0;
}
