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

const int N = 1e6 + 10;

ll n, a[N];

bool cmp(const ll &a, const ll &b){
  return a > b;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  FileIO("size");
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  map<ll, ll> rec;
  sort(a + 1, a + 1 + n, cmp);
  for(int i = 1; i <= n; i++){
    rec[a[i]] = a[i] + 1;
    while(i < n && a[i] - 1 == a[i + 1]){
      rec[a[i + 1]] = rec[a[i]];
      i++;
    }
  }
  int t;
  cin >> t;
  while(t--){
    ll x;
    cin >> x;
    if(rec.count(x) == 0){
      cout << x;
    }
    else{
      cout << rec[x];
    }
    cout << "\n";
  }
  return 0;
}
