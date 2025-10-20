#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a, b, c;
int v[N];

int main() {
  cin >> a >> b >> c;
  if(a == 0){
    if(b == 0 && c == 0){
      cout << "1\n1\n";
    }
    else {
      cout << "-1\n";
    }
    return 0;
  }
  if(b > a || c > a){
    cout << "-1\n";
    return 0;
  }
  for(int i = 0; i <= a + 2; i++) v[i] = 2;
  int db = a - b, dc = a - c, both = min(db, dc), oc = dc - both,  ob = db - both;
  int n = a + 2;
  int idx = n - 1;
  for(int i = 0; i < both; i++) v[idx--] = 1;
  for(int i = 0; i < oc; i++) v[idx--] = 4;
  for(int i = 0; i < ob; i++) v[idx--] = 5;
  cout << n << '\n';
  for(int i = 0; i < n; i++){
    if(i > 0) cout << ' ';
    cout << v[i];
  }
  cout << '\n';

  return 0;
}