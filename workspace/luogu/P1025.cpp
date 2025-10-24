#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 210, M = 10;

int n, k;

int dfs(int x, int l, int u){
  if(l == 1) return 1;
  int sum = 0;
  for(int i = u; i <= x / l; i++){
    sum += dfs(x - i, l - 1, i);
  }
  return sum; 
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cout << dfs(n, k, 1);
  return 0;
}
