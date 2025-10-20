#include<bits/stdc++.h>
using namespace std;

const int N = 25;

int n, f[N];
string a[N];

bool cmp(const string &a, const string &b){
  return b + a < a + b;
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, cmp);
  for(int i = 1; i <= n; i++){
    cout << a[i];
  }
  return 0;
}