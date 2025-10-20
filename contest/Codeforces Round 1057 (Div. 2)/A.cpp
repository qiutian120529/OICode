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
  int n;
  cin >> n;
  set<int> st;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    st.insert(x);
  }
  cout << st.size() << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
