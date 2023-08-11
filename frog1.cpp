
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





/*******************************Main function Program*******************/
ll arr[100005], n;
int dp[100005];

int helper(ll idx) {

	if (idx == n - 1) {
		return 0;
	}
	if (idx >= n) {
		return INT_MAX;
	}


	if (dp[idx] != -1) {
		return dp[idx];
	}
	ll left = abs(arr[idx] - arr[idx + 1]) + helper(idx + 1);

	ll right = INT_MAX;
	if (idx + 2 < n) {
		right = abs(arr[idx] - arr[idx + 2]) + helper(idx + 2);
	}
	return dp[idx] = min(left, right);
}

void solve() {

	// int n;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	rep(i, 0, n) {
		cin >> arr[i];
	}

	cout << helper(0);

}





int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}