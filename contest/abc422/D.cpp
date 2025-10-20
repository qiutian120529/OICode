#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 2e6;

int n, k, a[N];

void build(int st, int l, int r, int sum){
  if(l == r){
    a[l] = sum;
    return ;
  }
  int mid = l + r >> 1;
  build(st << 1, l, mid, sum / 2);
  build(st << 1 | 1, mid + 1, r, sum - sum / 2);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> k;
  build(1, 1, 1 << n, k);
  bool f = 0;
  for(int i = 1; i < (1 << n); i++){
    if(a[i] != a[i + 1]){
      f = 1;
      break;
    }
  }
  cout << f << "\n";
  for(int i = 1; i <= (1 << n); i++){
    cout << a[i] << " ";
  }
  return 0;
}
