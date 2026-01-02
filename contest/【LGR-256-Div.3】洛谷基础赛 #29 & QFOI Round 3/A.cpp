#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n,  m, r[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> r[i];
  }
  for(int i = 1; i <= m; i++){
    int p, d;
    string s;
    cin >> p >> d >> s;
    if(s == "Completed"){
      r[p] = d;
    }
  }
  for(int i = 1; i <= n; i++){
    cout << r[i] << " ";
  }
  return 0;
}
