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

const int N = 110;

int n, a[N], ans;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  int avg = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    avg += a[i];
  }
  avg /= n;
  for(int i = 1; i <= n; i++) a[i] -= avg;
  for(int i = 1; i <= n; i++){
    if(a[i] != 0) ans++;
    a[i + 1] += a[i];
  }
  cout << ans;
  return 0;
}
