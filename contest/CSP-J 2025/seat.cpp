#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 110;

int n, m;

struct P{
  int x, id;
}a[N];

bool cmp(const P &a, const P &b){
  return a.x > b.x;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n * m; i++){
    cin >> a[i].x;
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n * m, cmp);
  int p = 0;
  for(int j = 1; j <= m; j++){
    if(j & 1){
      for(int i = 1; i <= n; i++){
        if(a[++p].id == 1){
          cout << j << " " << i;
          return 0;
        }
      }
    }
    else{
      for(int i = n; i >= 1; i--){
        if(a[++p].id == 1){
          cout << j << " " << i;
          return 0;
        }
      }
    }
  }
  return 0;
}
