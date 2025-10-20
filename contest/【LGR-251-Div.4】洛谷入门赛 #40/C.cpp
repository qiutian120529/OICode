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
  int cnt = 0;
  for(int i = 1; i < s.size(); i++){
    cnt += s[i] != '0';
  }
  cout << (cnt == 0 && s[0] != '0' ? "Yes" : "No");
  return 0;
}
