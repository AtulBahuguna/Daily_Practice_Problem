#include<bits/stdc++.h>
using namespace std;
string curr;


/**********************Brute Force********************/
void solve(int n) {
	if (n == 0) {
		cout << curr << endl;
		return;
	}
	curr.push_back('0');
	solve(n - 1);
	curr.pop_back();
	curr.push_back('1');
	solve(n - 1);
	curr.pop_back();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	int n; cin >> n;
	solve(n);
	return 0;
}