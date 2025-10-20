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

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  string s;
  cin >> s;
  int n = s.size();
  for(int i = s.size() - 1; i >= 0; i--){
    cin.putback(s[i]);
  }
  for(int i = 1; i <= n; i++){
    char c;
    cin >> c;
    if(i == (n + 1) / 2) continue;
    cout << c;
  }
  return 0;
}
