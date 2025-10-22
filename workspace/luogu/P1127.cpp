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

const int N = 1010;

int n, ind[N], oud[N];
string s[N];
vector<int> g[N];
bool vis[N];

void dfs(int u, string t, int x){
  if(x == n){
    t = t.substr(0, t.size() - 1);
    cout << t;
    exit(0);
  }
  for(int v : g[u]){
    if(!vis[v]){
      vis[v] = 1;
      dfs(v, t + s[v] + '.', x + 1);
      vis[v] = 0;
    }
  }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    ind[s[i][0]]++, oud[s[i][s[i].size() - 1]]++;
  }
  sort(s + 1, s + 1 + n);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i != j && s[i][s[i].size() - 1] == s[j][0]){
        g[i].push_back(j);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(ind[s[i][0]] == oud[s[i][0]] + 1){
      vis[i] = 1;
      dfs(i, s[i] + '.', 1);
      vis[i] = 0;
    }
  }
  vis[1] = 1;
  dfs(1, s[1] + '.', 1);
  vis[1] = 0;
  cout << "***";
  return 0;
}
