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

const int N = 1e5 + 10;

struct Tree{
  struct Node{
    ll cnt, sum;
  }tr[N << 2];

  Node comb(const Node &a, const Node &b){
    Node tmp = {a.cnt + b.cnt, a.sum + b.sum};
    return tmp;
  }

  void build(int rt, int l, int r){
    if(l == r){
      tr[rt] = {0, 0};
      return ;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tr[rt] = comb(tr[rt << 1], tr[rt << 1 | 1]);
  }

  void modify(int rt, int l, int r, int p, int v){
    if(p < l || r < p) return ;
    if(l == r){
      tr[rt].cnt++;
      tr[rt].sum += v;
      return ;
    }
    int mid = l + r >> 1;
    modify(rt << 1, l, mid, p, v);
    modify(rt << 1 | 1, mid + 1, r, p, v);
    tr[rt] = comb(tr[rt << 1], tr[rt << 1 | 1]); 
  }

  int query(int rt, int l, int r, int k){
    // std::cout << rt << ' ' << l << ' ' << r << ' ' << k << '\n';
    if(l == r){
      return tr[rt].cnt * (tr[rt].sum <= k);
    }
    int mid = l + r >> 1;
    if(tr[rt << 1].sum <= k){
      return tr[rt << 1].cnt + query(rt << 1 | 1, mid + 1, r, k - tr[rt << 1].sum);
    }
    return query(rt << 1, l, mid, k);
  }
}T;

int n, m, a[N];

void solve(){
  vector<pii> b;
  unordered_map<int, int> rec;
  cin >> n >> m;
  T.build(1, 1, n);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    b.push_back({a[i], i});
  }
  sort(b.begin(), b.end());
  for(int i = 0; i < n; i++){
    rec[b[i].second] = i + 1;
  }
  for(int i = 1; i <= n; i++){
    // std::cout << T.query(1, 1, n, m - a[i]) << std::endl;
    cout << i - T.query(1, 1, n, m - a[i]) - 1 << " ";
    T.modify(1, 1, n, rec[i], a[i]);
  }
  cout << "\n";
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
