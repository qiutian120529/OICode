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

string s, t;

int ans = 1;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> s >> t;
  int n = s.size();
  s = '#' + s;
  t = '#' + t;
  for(int i = 1; i <= n; i++){
    for(int j = 2; j <= n; j++){
      if(s[i] == t[j] && s[i + 1] == t[j - 1]) ans *= 2;
    }
  }
  cout << ans;
  return 0;
}
