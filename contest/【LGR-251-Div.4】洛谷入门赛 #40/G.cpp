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
  int n;
  cin >> n;
  vector<vector<int> > a;
  a.assign(5, vector<int> (n + 5));
  for(int i = 1; i <= n; i++){
    cin >> a[1][i];
  }
  for(int i = 1; i <= n; i++){
    cin >> a[2][i];
  }
  string s;
  cin >> s;
  int m = s.size();
  s = '#' + s;
  stack<int> st;
  int sum = 0;
  for(int i = 1; i <= m; i++){
    if(s[i] == 'a' || s[i] == 'b'){
      st.push(s[i] - 'a' + 1);
    }
    if(isdigit(s[i])){
      sum = sum * 10 + s[i] - '0';
    }
  }
  while(st.size())
    sum = a[st.top()][sum], st.pop();
  cout << sum;
  return 0;
}
