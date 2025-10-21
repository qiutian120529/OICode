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

const int N = 2e6 + 10, inf = 1e9;

int n, m, a[N];

struct Tree{
  int tr[N << 2];

  int comb(const int &a, const int &b){
    return min(a, b);
  }

  void build(int st, int l, int r){
    if(l == r){
      tr[st] = a[l];
      return ;
    }
    int mid =(l + r) >> 1;
    build(st << 1, l, mid);
    build(st << 1 | 1, mid + 1, r);
    tr[st] = comb(tr[st << 1], tr[st << 1 | 1]);
  }

  int query(int st, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return inf;
    if(ql <= l && r <= qr) return tr[st];
    int mid = (l + r) >> 1;
    return comb(query(st << 1, l, mid, ql, qr), query(st << 1 | 1, mid + 1, r, ql, qr));
  }
}T;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  T.build(1, 1, n);
  for(int i = 1; i <= n; i++){
    int x = T.query(1, 1, n, max(0, i - m), i - 1);
    cout << (x == inf ? 0 : x) << "\n";
    // else cout << 0 << "\n";
  }
  return 0;
}