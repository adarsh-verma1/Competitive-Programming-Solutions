#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


ll binpow(ll a, ll b) {
	a %= mod;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a ) % mod;
		b >>= 1;
	}
	return res;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("Input.txt" , "r" , stdin);
// 	freopen("Output.txt" , "w" , stdout);
// #endif
	ll n, q;
	char temp;
	cin >> n >> q;
	map<ll, ll> impossible_states;
	for (int i = 0; i < q; i++) {
		ll idx;
		cin >> idx;
		impossible_states[idx]++;
	}
	for (int i = 0; i < q; i++) {
		cin >> temp;
	}

	ll res = 1;
	for (auto &x : impossible_states) {
		res = res * (26 - x.second);
		res %= mod;
		res = res * binpow(26, n - impossible_states.size());
		res %= mod;
	}

	cout << res << "\n";
}