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

const int N = 30;

double a[N], ans[N], sum;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t = 1;
  while(t){
    int n, r;
    cin >> n >> r;
    if(n == 0 && r == 0){
      break;
    }
    sum = 0;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
      ans[i] = 0;
    }
    for(int st = 0; st < (1 << n); st++){
      int cnt = 0;
      for(int j = 0; j < n; j++){
        cnt += (st >> j) & 1;
      }
      if(cnt != r) continue;
      double tot = 1;
      for(int j = 0; j < n; j++){
        bool bit = (st >> j) & 1;
        if(bit) tot *= a[j + 1];
        else tot *= (1 - a[j + 1]);
      }
      for(int j = 1; j <= n; j++){
        ans[j] += ((st >> (j - 1)) & 1) * tot;
      }
      sum += tot;
    }
    cout << "Case " << t << ":\n";
    t++;
    for(int i = 1; i <= n; i++){
      cout <<  fixed << setprecision(6) << ans[i] / sum << "\n";
    }
  }
  return 0;
}
