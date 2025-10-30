#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10;

struct node{
  int s, t, id;
}task[N];

bool cmp(const node &a, const node & b){
  return a.t < b.t;
}

int n, m;

struct P{
  int finish, id;
  bool operator < (const P &i) const {
    if(finish != i.finish){
      return finish > i.finish;
    }
    return id > i.id;
  }
};

priority_queue<P> Q, q;

vector<int> ans[N];

signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> task[i].s >> task[i].t;
    task[i].id = i;
  }
  sort(task + 1, task + 1 + n, cmp);
  for(int i = 1; i <= m; i++){
    q.push({0, i});
  }
  for(int i = 1; i <= n; i++){
    while(Q.size()){
      auto [t, id] = Q.top();
      if(t > task[i].t) break;
      q.push({0, id});
      Q.pop();
    }
    if(q.size()){
      auto [_, id] = q.top();
      q.pop();
      Q.push({task[i].s + task[i].t, id});
      ans[id].push_back(task[i].id);
    }
    else{
      auto [t, id] = Q.top();
      Q.pop();
      Q.push({t + task[i].s, id});
      ans[id].push_back(task[i].id);
    }
  }
  for(int i = 1; i <= m; i++){
    cout << ans[i].size() << " ";
    sort(ans[i].begin(), ans[i].end());
    for(int j : ans[i]){
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}
