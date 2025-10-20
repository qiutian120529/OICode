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

void solve(){
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == s[(i - 1 + s.size()) % s.size()]){
      cout << i << "\n";
      return ;
    }
  }
  cout << -1 << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
