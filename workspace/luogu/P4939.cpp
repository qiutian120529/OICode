#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 1e7 + 10;

int n, m, c[N];

void add(int x, int k){
  for(; x <= n; x += x & -x){
    c[x] += k;
  }
}

int query(int x){
  int sum = 0;
  for(; x; x -= x & -x){
    sum += c[x];
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n >> m;
  for(int i = 1, op, l, r; i <= m; i++){
    cin >> op;
    if(op == 0){
      cin >> l >> r;
      add(l, 1), add(r + 1, -1);
    }
    else{
      cin >> l;
      cout << query(l) << "\n";
    }
  }
  return 0;
}