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

const int N = 1e5 + 10, L = 17;

int n, m, a[N];

struct ST{
  int f[L][N], log_2[N];

  void init(){
    for(int i = 1; i <= n; i++){
      f[0][i] = a[i];
    }
    for(int i = 1; i < L; i++){
      for(int j = 1; j + (1 << i) - 1 <= n; j++){
        f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
      }
    }
    for(int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1;
  }

  int query(int l, int r){
    int k = log_2[r - l + 1];
    return min(f[k][l], f[k][r - (1 << k) + 1]);
  }
}st;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  st.init();
  for(int i = 1; i <= n - m + 1; i++){
    cout << st.query(i, i + m - 1) << "\n";
  }
  return 0;
}
