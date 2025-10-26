#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 10;

int vis[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    cout << n * (1 << k) << "\n";
  }
  return 0;
}
