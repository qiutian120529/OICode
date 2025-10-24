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

int n;

void solve(){
  cin >> n;
  unordered_map<int, int> a, b;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1, x; i <= n; i++){
    cin >> b[i];
  }
  stack<int> st;
  int k = 1;
  for(int i = 1; i <= n; i++){
    st.push(a[i]);
    while(st.size() && st.top() == b[k]){
      k++;
      st.pop();
    }
  }
  if(st.size() != 0 || k != n + 1){
    cout << "No\n";
  }
  else{
    cout << "Yes\n";
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
