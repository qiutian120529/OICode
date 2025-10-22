#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) do { \ 
  freopen((x ".in"), "r", stdin); \ 
} while(0)
#define FileOut(x) do { \
  freopen((x ".out"), "w", stdout); \ 
} while(0)
#define FileIO(x) do { \ 
  FileIn(x); FileOut(x); \
} while(0) 

using namespace std;

const int N = 25;

int x, y, z, vis[N][N][N];
vector<int> ans;

void dfs(int a, int b, int c){
  if(vis[a][b][c]) return;
  vis[a][b][c] = 1;
  if(a == 0) ans.push_back(c);
  int ta = x - a, tb = y - b, tc = z - c;
  dfs(a + min(ta, c), b, c - min(ta, c));
  dfs(a + min(ta, b), b - min(ta, b), c);
  dfs(a - min(a, tb), b + min(a, tb), c);
  dfs(a, b + min(c, tb), c - min(c, tb));
  dfs(a - min(a, tc), b, c + min(a, tc));
  dfs(a, b - min(b, tc), c + min(b, tc));
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> x >> y >> z;
  dfs(0, 0, z);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for(int x : ans) cout << x << " ";
  return 0;
}
