#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, k;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  if(!--k){
    return !bool(cout << 0);
  }
  for(int i = 1; i <= n; i++){
    if(!k){
      break;
    }
    if(k <= 1ll << (n - i)){
      cout << i << " ";
      k--;
    }
    else{
      k -= (1ll << (n - i));
    }
  }
  return 0;
}
