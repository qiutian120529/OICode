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

const int N = 110;

string s;
bool vis[N];
stack<int> st;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //FileIO
  cin >> s;
  int n = s.size();
  s = '#' + s;
  for(int i = 1; i <= n; i++){
    if(s[i] == '(' || s[i] == '['){
      st.push(i);
    }
    else if(st.size()){
      string t = "";
      t += s[st.top()];
      t += s[i];
      if(t == "()" || t == "[]"){
        vis[st.top()] = vis[i] = 1;
        st.pop();
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(vis[i]){
      cout << s[i];
    }
    else{
      if(s[i] == '(' || s[i] == ')'){
        cout << "()";
      }
      else{
        cout << "[]";
      }
    }
  }
  return 0;
}
