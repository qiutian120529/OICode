#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

string s;
vector<int> num;

bool cmp(const int &a, const int &b){
  return a > b;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(isdigit(s[i])){
      num.push_back(s[i] - '0');
    }
  }
  sort(num.begin(), num.end(), cmp);
  for(int i : num){
    cout << i;
  }
  return 0;
}
