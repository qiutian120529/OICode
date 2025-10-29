#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N], found = 1;

unordered_map<ll, int> vis;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if(n <= 20){
    for(int st = 0; st < (1 << n); st++){
      ll sum = 0;
      for(int i = 0; i < n; i++){
        if((st >> i) & 1){
          sum += a[i + 1];
        }
        else{
          sum -= a[i + 1];
        }
      }
      if(vis[sum] > 0){
        cout << "Yes";
        return 0;
      }
      vis[sum]++;
    }
    cout << "No";
  }
  else{
    cout << "Yes";
  }
  return 0;
}