#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 2e5 + 10;

int n, q, fa[N], cnt[N], f[N];

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v){
  int FA = find(u), FB = find(v);
  if(FA != FB){
    fa[FA] = FB;
    cnt[FB] += cnt[FA];
    cnt[FA] = 0;
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    fa[i] = i;
  }
  while(q--){
    int op;
    cin >> op;
    if(op == 1){
      int u, v;
      cin >> u >> v;
      merge(u, v);
    }
    else if(op == 2){
      int v;
      cin >> v;
      if(f[v]) cnt[find(v)]--;
      else cnt[find(v)]++;
      f[v] ^= 1;
    }
    else{
      int v;
      cin >> v;
      cout << (cnt[find(v)] > 0 ? "Yes\n" : "No\n");
    }
  }
  return 0;
}
