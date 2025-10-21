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

const int N = 260;
  
string s;
int k, a[N], n;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> s >> k;
  int n = s.size();
  s = "#" + s;
  for(int i = 1; i <= n; i++){
    a[i] = s[i] - '0';
  }
  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= n; j++){
      if(a[j] > a[j + 1]){
        a[j] = 0;
        for(int o = j; o <= n; o++){
          swap(a[o], a[o + 1]);
        }
        n--;
        break;
      }
    }
  }
  int f = 0;
  for(int i = 1; i <= n; i++){
    f |= (a[i] != 0);
    if(f){
      cout << a[i];
    }
  }
  if(!f) cout << 0;
  return 0;
}
