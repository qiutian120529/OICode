#include<bits/stdc++.h>
using namespace std;

const int N = 70;

int n, a[N], f[N], summ, mx = 0, ans, rec[N], tag, cnt;

void dfs(int x, int sum, int up){
  // if(++cnt > 100000000 / (sum - mx)) return ;
	if(tag) return ;
	if(x == n + 1){
		if(!sum){
			tag = 1;	
		}
		return ;
	}
	for(int i = 1; i <= n; i++){
    if(!f[i] && sum + a[i] <= up){
      f[i] = 1;
      dfs(x + 1, (sum + a[i]) % up, up);
      f[i] = 0;
    }
	}
}

bool check(int x){
  fill(f + 1, f + 1 + n, 0);
  cnt = 0;
	dfs(1, 0, x);
	return tag;
}

bool cmp(int a, int b){
  return a > b;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		summ += a[i];
		mx = max(mx, a[i]);
	}
  sort(a + 1, a + 1 + n, cmp);
	for(int i = mx; i <= summ; i++){
		if(summ % i) continue;
    if(check(i)){
			cout << i;
			return 0;
		}
	}
  // cout << check(86);
	return 0;
} 