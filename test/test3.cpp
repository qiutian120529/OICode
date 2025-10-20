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

const int N = 1e6 + 5;

ll m, a[N], sum[N];
string ttt;
deque<int> q;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // FileIO("stars");
  cin >> m >> ttt;
  for(int i = 0; i < ttt.size(); i++){
    a[i + 1] = ttt[i] - '0';
    q.push_back(i + 1);
  }
  while(m--){
    int x = q.back();
    q.pop_back();
    q.push_front(x);
    q.push_front(x);
  }
  int sz = q.size();
  while(sz--){
    int x = q.front();
    q.pop_front();
    q.push_back(x);
    sum[x]++;
  }
  for(int i = 1; i <= ttt.size(); i++){
    a[i] -= (sum[i] - 1) * 9;
    (a[i] += 2e9) %= 10;
  }
  while(q.size()){
    int x = q.front();
    q.pop_front();
    if(sum[x] > 1){
      cout << 9;
      sum[x]--;
    }
    else{
      cout << a[x];
    }
  }
  return 0;
}
