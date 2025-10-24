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

int a, b;

void solve(){
  cin >> a >> b;
  cout << a / b << ".";
  a %= b;
  vector<int> digit;
  unordered_map<int, int> vis;
  int p = 0;
  while(a){
    a *= 10;
    if(vis[a] != 0){
      p = vis[a];
      break;
    }
    digit.push_back(a / b);
    vis[a] = digit.size();
    a %= b;
  }
  if(!a){
    for(int x : digit){
      cout << x;
    }
    cout << "\n";
  }
  else{
    for(int i = 0; i < p - 1; i++){
      cout << digit[i];
    }
    cout << '(';
    for(int i = p - 1; i < digit.size(); i++){
      cout << digit[i];
    }
    cout << ")\n";
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // FileIO("");
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
/*
4
1 2
2 6
1 7
3 13
*/