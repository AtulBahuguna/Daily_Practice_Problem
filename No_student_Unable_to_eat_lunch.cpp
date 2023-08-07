#include<bits/stdc++.h>
using namespace std;

//Problem Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/


int Solve(vector<int>&students, vector<int>&sandwiches) {
	stack<int>st;
	queue<int>q;

	int n = students.size();
	for (int i = 0; i < n; i++) {
		q.push(students[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		st.push(sandwiches[i]);
	}

	int x = 0;
	while (st.size() > 0) {
		if (st.top() == q.front()) {
			st.pop();
			q.pop();
			x = 0;
		} else {
			x++;
			q.push(q.front());
			q.pop();
		}
		if (x == q.size()) {
			break;
		}
	}
	return q.size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	int n;
	cin >> n;

	vector<int>students(n);
	vector<int>sandwiches(n);
	for (auto &it : students) {
		cin >> it;
	}
	for (auto &it : sandwiches) {
		cin >> it;
	}

	cout << Solve(students, sandwiches) << endl;
	return 0;
}