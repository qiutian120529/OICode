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
  int n;
  cin >> n;
  vector<int> a(n + 5, 0);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int k, x;
  cin >> k >> x;
  for(int i = 1; i <= n; i++){
    if(a[i] == x && !--k){
      cout << i;
      return 0;
    }
  }
  cout << "Error";
  return 0;
}
