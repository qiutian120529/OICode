#include<bits/stdc++.h>
using namespace std;

const int N = 510;

int num[N];
int len, n;

vector<int> mul(vector<int> A, int B) {
	int dig = 0;
	vector<int> res;
	for(int j = 0; j < A.size(); j++){
		int tmp = A[j] * B + dig;
		res.push_back(tmp % 10);
		dig = tmp / 10;
	}
	while(dig > 0){
		res.push_back(dig % 10);
		dig /= 10;
	}
	return res;
}

int main() {
	cin >> n;
	int sum = 0;
	for(int i = 2; sum < n; i++, len++){
		num[len] = i;
		sum += i;
	}
	if(sum - n == 1){
		num[len - 1]++;
		num[0] = -1;
	}
	if(sum - n > 1){
		num[sum - n - 2] = -1;
	}
	vector<int> ans;
  ans.push_back(1);
	for(int i = 0; i < len; i++){
		if(num[i] == -1){
			continue;
		}
		cout << num[i] << " ";
		ans = mul(ans, num[i]);
	}
	cout << "\n";	
  reverse(ans.begin(), ans.end());
	for(int x : ans){
    cout << x;
  }
	return 0;
}
