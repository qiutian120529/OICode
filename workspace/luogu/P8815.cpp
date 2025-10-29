#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

string s;

struct P {
  int div, val;
  char sym;
} ttt[N];

int head = 0;

vector<P> rec;

vector<char> ans;

struct node {
  int x, y;
} a[N];

int t, st[N], cnt1, cnt2;

inline int get (char ch) {
  if (ch == '(') return -1;
  if (ch == '|') return 1;
  return 2;
}

inline bool dfs (int u) {
  if (rec[u].sym == '#') return rec[u].val;
  bool l = dfs(a[u].x);
  if (rec[u].sym == '&') {
    if (!l) {
      cnt1++;
      return 0;
    }
    return l & dfs(a[u].y);
  }
  if (l) {
    cnt2++;
    return 1;
  }
  return l | dfs(a[u].y);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  getline(cin, s);
  for (int i = 0, o = 0; i < s.size(); i++) {
    if (isdigit(s[i])) rec.push_back({0, (s[i] - '0'), '#'});
    else if (s[i] == '(') o += 3;
    else if (s[i] == ')') o -= 3;
    else{
      while (head && ttt[head].div >= get(s[i]) + o) {
        rec.push_back(ttt[head]);
        head--;
      }
      ttt[++head] = {get(s[i]) + o, 0, s[i]};
    }
  }
  while (head) {
    rec.push_back(ttt[head]);
    head--;
  }
  for (auto i = 0; i < rec.size(); i++) {
    if (rec[i].sym == '|' || rec[i].sym == '&') {
      a[i] = {st[t - 1], st[t]};
      t -= 2;
    }
    st[++t] = i;
  }
  cout << dfs(st[1]) << "\n";
  cout << cnt1 << " " << cnt2;
  return 0;
}
