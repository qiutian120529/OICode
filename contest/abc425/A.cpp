#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 0;

int n, ans;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    if(i & 1){
      ans -= i * i * i;
    }
    else{
      ans += i * i * i;
    }
  }
  cout << ans;
  return 0;
}
