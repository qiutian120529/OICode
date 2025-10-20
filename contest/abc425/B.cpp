#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 15;

int n, vis[N], a[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> a[i];
    x = a[i];
    if(x == -1) continue;
    if(vis[x]){
      cout << "No";
      return 0;
    }
    vis[x] = 1;
  }
  cout << "Yes\n";
  for(int i = 1; i <= n; i++){
    if(a[i] == -1){
      for(int j = 1; j <= n; j++){
        if(!vis[j]){
          vis[j] = 1;
          cout << j << " ";
          break;
        }
      }
    }
    else{
      cout << a[i] << " ";
    }
  }
  return 0;
}
