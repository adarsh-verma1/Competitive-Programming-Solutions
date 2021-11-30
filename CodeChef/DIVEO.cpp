
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
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;

	if (a < 0 && b < 0) {
		if (a > b) {
			if (n % 2 == 0) {
				cout << a << endl;
				return;
			}
			else {
				cout << b << endl;
				return;
			}
		}
		else {
			if (n % 2 == 0) {
				cout << max(a + b, a) << endl;
				return;
			}
			else {
				cout << b << endl;
				return;
			}
		}
	}

	while (n % 2 == 0)
	{
		if (a < 0)
			ans = a;
		else
			ans += a;
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			if (b > 0)
				ans += b;
			else
				break;
			n = n / i;
		}
	}
	if (b < 0)
		ans += b;

	if (n > 2 && b >= 0)
		ans += b;

	cout << ans << endl;
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