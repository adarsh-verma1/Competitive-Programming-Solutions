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

ll power(ll value1, ll power1) {
	if (power1 == 0)
		return 1LL;
	if (power1 == 1)
		return value1;
	if (power1 % 2 == 0) {
		ll x = power(value1, power1 >> 1);
		ll y = x * x;
		return y;
	}
	else {
		ll x = power(value1, power1 - 1);
		ll val = value1 * x;
		return val;
	}
}

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

ll nextPowerOf2(ll n)
{
	if (n == 1)
		return 0;

	ll count = 0;

	if (n && !(n & (n - 1)))
		return n;

	while ( n != 0) {
		n >>= 1;
		count += 1;
	}

	return count;
}

void solve() {
	ll n;
	cin >> n;

	vvi a(n, vi(5));
	FOR(n) FORj(0, 5) cin >> a[i][j];

	vi cnt(5, 0);

	FOR(5) {
		int temp = 0;
		FORj(0, n) {
			if (a[j][i] == 1)
				temp++;
		}
		cnt[i] = temp;
	}

	bool flag = false;
	for (int k = 0; k < 5; k++) {
		if (cnt[k] >= n / 2) {
			for (int l = k + 1; l < 5; l++) {
				if (cnt[l] >= n / 2) {
					int diff = n - cnt[l];
					if (diff == 0 || cnt[k] == n) {
						cout << "YES" << endl;
						return;
					}

					FOR(n) {
						if (a[i][k] == 0) {
							if (a[i][l] == 1)
								flag = true;
							else {
								flag = false;
								break;
							}
						}
					}

					if (flag) {
						cout << "YES" << endl;
						return;
					}
				}
			}
		}
	}

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