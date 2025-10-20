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

const int N = 1e5 + 10;

int n, a[N];

bool cmp(const int &a, const int &b){
  return a > b;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];  
  }
  sort(a + 1, a + 1 + n, cmp);
  ll ans = 0, cnt = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] * 1ll * i >= ans){
      cnt = a[i];
    }
    ans = max(ans, a[i] * 1ll * i);
  }
  cout << ans << " " << cnt;
  return 0;
}
