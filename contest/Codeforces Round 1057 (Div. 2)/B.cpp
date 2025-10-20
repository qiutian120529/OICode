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

const int N = 35;

int a[N], b[N], c[N];

void solve(){
  int x, y, z;
  cin >> x >> y >> z;
  for(int i = 0; i <= 31; i++){
    bool bx = (x >> i) & 1, by = (y >> i) & 1, bz = (z >> i) & 1;
    int cnt = bx + by + bz;
    if(cnt == 2){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
