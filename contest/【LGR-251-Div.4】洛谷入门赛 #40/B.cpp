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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a == b || b == c || a == c){
    cout << "Report";
  }
  else if(a == d){
    cout << "A";
  }
  else if(b == d){
    cout << "B";
  }
  else if(c == d){
    cout << "C";
  }
  else{
    struct P{
      int x;
      char c;
      bool operator < (const P &i) const {
        return x < i.x;
      }
    }rec[5];
    rec[1] = {a, 'A'}, rec[2] = {b, 'B'}, rec[3] = {c, 'C'};
    sort(rec + 1, rec + 1 + 3);
    cout << rec[2].c;
  }
  return 0;
}
