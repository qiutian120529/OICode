#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, cnt, tot;

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  cout << (n % 3 == 2 ? "Bob" : "Ayano");
  return 0;
} 