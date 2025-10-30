#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 110;

int n, a[N], sum;
bool dp[N][N * N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    sum += a[i];
  }
  dp[0][0] = 1;  
  for(int i = 1; i <= n; i++){
    for(int k = i; k >= 1; k--){
      for(int j = sum; j >= a[i]; j--){
        dp[k][j] |= dp[k - 1][j - a[i]];
      }
    }
  }
  for(int i = sum / 2; i >= 0; i--){
    if(dp[n / 2][i]){
      cout << i;
      break;
    }
  }
  return 0;
}
