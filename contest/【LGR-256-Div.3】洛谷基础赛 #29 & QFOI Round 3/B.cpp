#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, d;

long double plane[N];

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> d;
  int s, t, h;
  cin >> s >> t >> h;
  int v = (t - s);
  for(int i = 1; i <= n; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if(abs(h - z) <= d){
      if(x == s && y == t){
        plane[i] = -1;
      }
      else if(s <= x && y <= t){
        plane[i] = (x - s) * 1.0 / abs(v - (y - x)) * v + s;
      }
      else if(x <= s && t <= y){
        plane[i] = (s - x) * 1.0 / abs(v - (y - x)) * (y - x) + x;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(plane[i] == -1){
      cout << "Always\n";
    }
    else if(plane[i] == 0){
      cout << "No\n";
    }
    else{
      cout << fixed << setprecision(12) << plane[i] << "\n";
    }
  }
  return 0;
}

