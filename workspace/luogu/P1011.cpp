#include<bits/stdc++.h>
using namespace std;

int n, a, m, x, f[30];

int main(){
  cin >> a >> n >> m >> x;
  f[1] = 1;
  for(int i = 2; i <= n; i++){
    f[i] = f[i - 1] + f[i - 2];
  }
  int b = (m - (f[n - 3] + 1) * a) / (f[n - 2] - 1);
  cout << (f[x - 2] + 1) * a + (f[x - 1] - 1) * b;
  return 0;
}