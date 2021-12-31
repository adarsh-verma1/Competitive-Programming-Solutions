/*
	Author: ADARSH VERMA
	Codeforces: adarsh_verma_
	Codechef: adarsh_verma_
*/

#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll  vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>
#define pb push_back
#define um unordered_map
#define F first
#define S second
#define endl "\n"
#define FOR(n) for(int i=0; i<n; i++)
#define FORj(start, n) for(int j= start; j<n; j++)
#define FORd(n) for(int i=n; i>=0; i--)
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// ll gcd(ll a, ll b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }

// ll lcm( ll a, ll b) {
// 	ll prod = (a * b) % mod;

// 	return (prod / gcd(a, b));
// }

// bool ispowerof2(ll n)
// {
//    if(n==0)
//     return false;
//    return (ceil(log2(n)) == floor(log2(n)));
// }

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

// ll combine(int n, int r) {
// 	if (r == 0 || r == n)
// 		return 1;
// 	ll one = combine(n - 1, r);
// 	ll two = combine(n - 1, r - 1);
// 	return (one + two);
// }

// ll fact(int n) {
// 	if (n == 0 || n == 1)
// 		return 1;
// 	ll one = fact(n - 1);
// 	return (n * one);
// }

// bool isPrime(int n) {
// 	vector<bool> sieve(n + 1, true);

// 	for (int i = 2; i * i <= n; i++) {
// 		if (sieve[i] == true) {
// 			for (int j = i * i; j <= n; j += i) {
// 				sieve[j] = false;
// 			}
// 		}
// 	}
// 	return sieve[n];
// }

// bool isPrime(int n) {
// 	if (n <= 1)
// 		return false;

// 	for (int i = 2; i < n; i++)
// 		if (n % i == 0)
// 			return false;

// 	return true;
// }
//
void solve() {
	int n;
	cin >> n;

	vi u(n);
	vll s(n);
	FOR(n) cin >> u[i];
	FOR(n) cin >> s[i];

	int m = *max_element(u.begin(), u.end());
	// cout << m << endl;
	vvi val(m);
	FOR(n) {
		int row = u[i] - 1;
		val[row].pb(s[i]);
	}

	FOR(m) sort(val[i].begin(), val[i].end(), greater<>());

	vll sum(m, 0);
	int max_team_size = 0;
	FOR(m) {
		int n = val[i].size();
		max_team_size = max(max_team_size, n);
		ll temp = 0;
		for (int j = 0; j < n; j++)
			temp += val[i][j];

		sum[i] = temp;
	}

	vvi prefix_s(m);
	FOR(m) {
		int n = val[i].size();
		vi temp(n, 0);
		if (n == 0)
			continue;
		temp[n - 1] = val[i][n - 1];
		for (int j = n - 2; j >= 0; j--)
			temp[j] = temp[j + 1] + val[i][j];

		prefix_s[i] = (temp);
	}

	// FOR(m) {
	// 	int x = val[i].size();
	// 	for (int j = 0; j < x; j++)
	// 		cout << prefix_s[i][j] << " ";
	// 	cout << endl;
	// }


	for (int k = 1; k <= max_team_size; k++) {
		ll ans = 0;
		FOR(m) {
			int t_size = k;
			int x = val[i].size();

			int rem = x % t_size;
			// cout << "rem-- " << rem << endl;
			ll temp_sum = sum[i];
			if (rem != 0 && (x - rem - 1) >= 0) {
				temp_sum -= prefix_s[i][x - rem ];
				// cout << k << " " << i << " " << prefix_s[i][x - rem] << endl;
			}
			if (rem != x)
				ans += temp_sum;
		}
		cout << ans << " ";
	}

	FOR(n - max_team_size) cout << 0 << " ";
	cout << endl;

	// FOR(m) {
	// 	int x = val[i].size();
	// 	for (int j = 0; j < x; j++)
	// 		cout << val[i][j] << " ";
	// 	cout << endl;
	// }

	// FOR(m) cout << sum[i] << " ";
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