/*

user: Atul Bahuguna

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define F first
#define S second
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

/*****************************GCD function***********************/

int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}

	// make sure always pass abs(a) and abs(b);

	return gcd(b, a % b);
}


ll power(ll base, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2 == 1) {
			res = res * base;
			n--;
		}
		base = base * base;
		n /= 2;
	}

	return res;
}

bool is_prime[10000001];

void sieve() {

	ll maxN = 10000000;

	for (ll i = 1; i <= maxN; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= maxN; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= maxN; j += i) {
				is_prime[j] = false;
			}
		}
	}


}


/*******************************Main function Program*******************/


void solve() {

	string s;
	cin >> s;
	bool flag = true;
	int nice = 1;
	for (int i = 0; i < s.length(); i++) {
		if (!isupper(s[i])) {
			nice = 0;
		}

	}
	if (nice == 1) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
		return;
	}
	if (s.length() == 1) {
		cout << (char)toupper(s[0]) << endl;
	} else {
		for (int i = 1; i < s.length(); i++) {
			if (!isupper(s[i])) {
				flag = false;
			}
		}
		if (flag) {
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			s[0] = (char)toupper(s[0]);
			cout << s << endl;
		} else {
			cout << s << endl;

		}
	}


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}