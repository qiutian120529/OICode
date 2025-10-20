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

const int N = 10;

int n, x;
ll cnt[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1, x; i <= n; i++){
    cin >> x;
    while(x % 2 == 0) x /= 2, cnt[2]++;
    while(x % 3 == 0) x /= 3, cnt[3]++;
    while(x % 5 == 0) x /= 5, cnt[5]++;
  }
  cout << min({cnt[2], cnt[3], cnt[5]});
  return 0;
}
