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
#define FOR(n) for(int i=0; i<n; i++)
#define FORd(n) for(int i=n; i>=0; i--)
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int power(int value1, int power1) {
	if (power1 == 0)
		return 1;
	if (power1 == 1)
		return value1;
	if (power1 % 2 == 0) {
		int x = power(value1, power1 / 2);
		return x * x;
	}
	else {
		int x = power(value1, power1 - 1);
		return value1 * x;
	}
}

void solve() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << -1 << endl;
		return;
	}
	while (n-- != 1)
		cout << 9;
	cout << 8 << endl;
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