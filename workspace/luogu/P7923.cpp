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

const int N = 0, inf = 1e9;

int n;
char c;

struct P{
  string s;
  int x;
}l, r;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> c;
  l.x = -inf, r.x = inf;
  for(int i = 1; i <= n; i++){
    int v;
    char u, x, y;
    cin >> u >> x >> y;
    if(y == '-' || isdigit(y)){
      cin.putback(y);
      y = x;
    }
    cin >> v;
    if(x == '<' && y == '<'){
      if(v <= r.x){
        r = {"<", v};
      }
    }
    if(x == '<' && y == '='){
      if(v < r.x){
        r = {"<=", v};
      }
    }
    if(x == '>' && y == '>'){
      if(v >= l.x){
        l = {"<", v};
      }
    }
    if(x == '>' && y == '='){
      if(v > l.x){
        l = {"<=", v};
      }
    }
    // cout << "***" << u << x << y << v << "\n";
  }  
  if((l.x == r.x && (l.s.size() == 1 || r.s.size() == 1)) || l.x > r.x){
    cout << "No Answer!";
  }
  else if(l.x == r.x && l.s.size() == 2 && r.s.size() == 2){
    cout << c << "=" << l.x;
  }
  else if(l.x == -inf){
    cout  << c << r.s << r.x;
  }
  else if(r.x == inf){
    if(l.s[0] == '<') l.s[0] = '>';
    else l.s[0] = '<';
    cout << c << l.s << l.x;
  }
  else cout << l.x << l.s << c << r.s << r.x;
  return 0;
}
/*4 q
q<114514
q<1
q<=-114515
q<-114514*/