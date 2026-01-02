#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3 + 10;

int n, m;
bool f[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> f[i][j];
    }
  }
  int cnt1 = 0, cnt2 = 0;
  for(int i = 1; i <= n; i++){
    if(f[i][m]) cnt1++;
    if(f[m][i]) cnt2++;
  }
  cout << cnt2 << " " << cnt1 << " " << cnt1 + cnt2;
  return 0;
}
