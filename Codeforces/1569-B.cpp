/*
	Author: ADARSH VERMA
	Codeforces: adarsh_verma_
	Codechef: adarsh_verma_
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>
#define pb push_back
#define um unordered_map
#define F first
#define S second
#define endl "\n"
#define FORi(n) for(int i=0; i<n; i++)
#define FORj(n) for(int j=0; j<n; j++)
#define FORd(n) for(int i=n; i>=0; i--)
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// int power(int value1, int power1) {
// 	if (power1 == 0)
// 		return 1;
// 	if (power1 == 1)
// 		return value1;
// 	if (power1 % 2 == 0) {
// 		int x = power(value1, power1 / 2);
// 		return x * x;
// 	}
// 	else {
// 		int x = power(value1, power1 - 1);
// 		return value1 * x;
// 	}
// }

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<char>> ans(n, vector<char>(n, '?'));

	int cnt1 = 0, cnt2 = 0;
	for (char c : s) {
		if (c == '1')
			cnt1++;
		else
			cnt2++;
	}

	FORi(n) {
		FORj(n)
		if (i == j)
			ans[i][j] = 'X';
	}

	for (int k = 0; k < s.size(); k++) {
		if (s[k] == '1') {
			for (int i = 0; i < n; i++)
				if (ans[i][k] == '?') {
					ans[i][k] = '=';
					ans[k][i] = '=';
				}
		}
	}
	for (int k = 0; k < s.size(); k++) {
		int j;
		for (int i = k; i < n; i++)
			if (ans[k][i] == '?') {
				ans[k][i] = '+';
				ans[i][k] = '-';
				j = i + 1;
				break;
			}

		for (; j < n; j++)
			if (ans[k][j] == '?') {
				ans[k][j] = '-';
				ans[j][k] = '+';
			}

	}

	int check = 1;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] == '1') {
			for (int i = 0; i < n; i++) {
				if (ans[k][i] == '-' || ans[i][k] == '-') {
					check = 0;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (ans[k][i] == '+') {
					check = 1;
					break;
				}
				else
					check = 0;
			}

		}
		if (!check) break;
	}

	if (check) {
		cout << "YES" << endl;
		FORi(n) {
			FORj(n)
			cout << ans[i][j];
			cout << endl;
		}
	}
	else
		cout << "NO" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt" , "r" , stdin);
	freopen("Output.txt" , "w" , stdout);
#endif
	fast;
	tc{
		solve();
	}
	return 0;
}