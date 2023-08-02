#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}
	if (a == 0) {
		return b;
	}
	return a;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
}