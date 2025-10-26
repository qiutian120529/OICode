#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

string s;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  if(s == "Rejected"){
    cout << 0;
  }
  else{
    int x, y;
    cin >> x >> y;
    cout << y * 1ll + (x - 1) * 20;
  }
  return 0;
}
