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

const int N = 110;

int n, a[N];

int f(int x){
  int sum = 0;
  while(x){
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  a[0] = 1;
  for(int i = 1; i <= n; i++){
    a[i] = a[i - 1] + f(a[i - 1]);
  }
  cout << a[n - 1];
  return 0;
}
