#include<bits/stdc++.h>
using namespace std;

int n, x;
string s;
string mp[110];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> mp[i];
  }
  cin >> x >> s;
  if(mp[x] == s){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
  return 0;
}