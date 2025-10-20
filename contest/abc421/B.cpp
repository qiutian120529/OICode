#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y;

ll f(ll x){
  string s = to_string(x);
  reverse(s.begin(), s.end());
  ll sum = 0;
  for(char ch : s){
    sum = sum * 10 + (ch - '0');
  }
  return sum;
}

int main(){
  cin >> x >> y;
  for(int i = 3; i <= 10; i++){
    int t = y;
    y = f(x + y);
    x = t;
  }
  cout << y;
  return 0;
}