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
  vector<int> a(n + 5);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i < n; i++){
    if(i & 1){
      if(a[i] != a[i + 1]){
        cout << "No\n";
        return ;
      }
    }
    else{
      if(a[i] == a[i + 1]){
        cout << "No\n";
        return ;
      }
    }
  }
  cout << "Yes\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
