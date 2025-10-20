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

const int N = 0;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 5);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  while(q--){
    int m;
    cin >> m;
    unordered_map<int, int> f;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(!f[a[i] % m]){
        cnt++;
      }
      f[a[i] % m] = 1;
    }
    cout << cnt << "\n";
  }
  return 0;
}
