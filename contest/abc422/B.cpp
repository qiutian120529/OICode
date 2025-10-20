#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
#define FileIn(x) freopen(x".in", "r", stdin);
#define FileOut(x) freopen(x".out", "w", stdout);
#define FileIO(x) FileIn(x), FileOut(x);
using namespace std;

const int N = 25;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, f[N][N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char ch;
      cin >> ch;
      if(ch == '#'){
        f[i][j] = 1;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(f[i][j]){
        int cnt = 0;
        for(int k = 0; k < 4; k++){
          cnt += f[i + dx[k]][j + dy[k]];
        }
        if(cnt == 2 || cnt == 4);
        else{
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
