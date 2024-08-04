#include<bits/stdc++.h>
typedef long long ll;
#define FASTIO                              \
		ios_base::sync_with_stdio(false);  \
		cin.tie(NULL);
#define MOD 1000000007
using namespace std;
const static int maxn = 1e6;
int dp[1005][1005];
int solve(ll a[], ll n, ll m, ll sum, ll i, bool val) {
	if (sum % m == 0 && val)
		return 1;

	if (i >= n)
		return 0;

	if (dp[i][sum] != -1)
		return dp[i][sum];

	int one = solve(a, n, m, (sum + a[i]) % m, i + 1, true);
	int two = solve(a, n, m, sum, i + 1, (val || false));

	return (dp[i][sum] = (one || two));
}
int main() {
	FASTIO;

	ll n, m;
	cin >> n >> m;
	ll a[n];
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++)
			dp[i][j] = -1;
	}
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= m;
	}

	int ans = solve(a, n, m, 0, 0, false);
	if (ans)
		cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}