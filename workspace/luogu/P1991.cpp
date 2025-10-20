#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ld long double
using namespace std;

const int N = 510;

int s, p;
int x[N], y[N], fa[N];

struct P{
  double dis;
  int i, j;
};

vector<P> b;

double get(int x, int y, int xx, int yy){
  return sqrtl((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

bool cmp(const P &a, const P &b){
  return a.dis < b.dis;
}

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin >> s >> p;
  for(int i = 1; i <= p; i++){
    fa[i] = i;
  }
  for(int i = 1; i <= p; i++){
    cin >> x[i] >> y[i];
  }
  for(int i = 1; i <= p; i++){
    for(int j = i + 1; j <= p; j++){
      double dist = get(x[i], y[i], x[j], y[j]);
      b.push_back({dist, i, j});
      b.push_back({dist, j, i});
    }
  }
  sort(b.begin(), b.end(),cmp);
  vector<double> rec;
  int cnt = 0;
  for(auto e : b){
    double dis = e.dis;
    int i = e.i, j = e.j; 
    int FA = find(i), FB = find(j);
    if(FA != FB){
      fa[FA] = FB;
      //rec.push_back(dis);
      cnt++;
    }
    if(cnt == p - s){
      cout << fixed << setprecision(2) << dis;
      return 0;
    }
  }
  return 0;
}
