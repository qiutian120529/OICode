#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int cnt = 1, sum = 0, ans = n;
  for(int i = 2; i <= n; i++){
    if(a[i] != a[i - 1]) sum += cnt, cnt = 0;
    if(sum) ans--, sum--;
    cnt++;
  }
  cout << ans;
  return 0;
}
