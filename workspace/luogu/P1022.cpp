#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

char c, x;

int num, side = 1, sum, p, f = 1; // px = 2, x= 2 / p
bool have;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  while(cin >> c){
    if(isdigit(c)){
      num = num * 10 + (c - '0');
      have = 1;
    }
    else if('a' <= c && c <= 'z'){
      x = c;
      if(have)
        p += num * f * side;
      else
        p += f * side;
       num = 0, f = 1;
      have = 0;
    }
    else{
      sum += num * f * side;
      num = 0, f = 1, have = 0;
      if(c == '='){
        side = -1;
      }
      if(c == '+'){
        f = 1;
      }
      if(c == '-'){
        f = -1;
      }
    }
  }
  sum += num * f * side;
  cout << x << "=" << fixed << setprecision(3) << (-sum * 1.0 / p == -0.0 ? 0 : -sum * 1.0 / p);
  return 0;
}
