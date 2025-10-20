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

const int N = 0;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  int n, m;
  cin >> n >> m;
  vector<vector<char> > c;
  vector<vector<bool> > f;
  c.assign(n + 5, vector<char> (m + 5));
  f.assign(n + 5, vector<bool> (m + 5));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> c[i][j];
    }
  }
  for(int j = 1; j <= m; j++){
    queue<char> q;
    int p = n;
    for(int i = n; i >= 1; i--){
      if('A' <= c[i][j] && c[i][j] <= 'Z'){
        q.push(c[i][j]);
        f[i][j] = 1;
      }
      if(i == 1 || c[i][j] == '-'){
        while(q.size()){
          f[p][j] = 0;
          c[p][j] = q.front();
          p--;
          q.pop();
        }
        p = i - 1;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(f[i][j]) cout << '.';
      else cout << c[i][j];
    }
    cout << "\n";
  }
  return 0;
}
