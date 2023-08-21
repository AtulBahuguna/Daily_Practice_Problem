/*

user: Atul Bahuguna
problem: print any one subsequence whose sum is equal to the target value

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

bool recursion(int ind, vector<int>arr, vector<int>&ds, int sum, int target) {
	if (ind == arr.size()) {
		if (sum == target) {
			for (auto it : ds) {
				cout << it << " ";
			}
			return true;
		}
		return false;
	}
	//time to pick
	ds.push_back(arr[ind]);
	sum += arr[ind];
	if (recursion(ind + 1, arr, ds, sum, target))return true;
	ds.pop_back();
	sum -= arr[ind];
	if (recursion(ind + 1, arr, ds, sum, target))return true;
	return false;
}

void solve() {

	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	int target; cin >> target;
	vector<int>ds;
	if (recursion(0, arr, ds, 0, target)) {
		cout << endl;
	} else {
		cout << "No subsequence is there" << endl;
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T;
	cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}