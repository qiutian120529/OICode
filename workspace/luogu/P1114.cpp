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

const int N = 1e5 + 10, inf = 1e9;

int n, sum[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  unordered_map<int, pii> rec;
  for(int i = 1, x; i <= n; i++){
    sum[i] += sum[i - 1];
    cin >> x;
    if(x) sum[i]++;
    else sum[i]--;
    rec[sum[i]] = {min((rec[sum[i]].first == 0 && sum[i] != 0 ? inf : rec[sum[i]].first), i), i};
  }
  int ans = 0;
  for(int i = -n; i <= n; i++){
    ans = max(ans, rec[i].second - rec[i].first);
  }
  cout << ans;
  return 0;
}
