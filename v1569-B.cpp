/*
	Author: ADARSH VERMA
	Codeforces: adarsh_verma_
	Codechef: adarsh_verma_
*/

#include<bits/stdc++.h>
#include<algorithm>
#include<unistd.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vf vector<float>
#define vs vector<string>
#define vll  vector<ll>
#define vvi vector<vi>
#define vvc vector<vc>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pb push_back
#define um unordered_map
#define F first
#define S second
#define ipn ll n; cin>>n;
#define endl "\n"
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define FOR(n) for(int i=0; i<n; i++)
#define FORi(start, n) for(int i= start; i<n; i++)
#define FORj(start, n) for(int j= start; j<n; j++)
#define FORd(n) for(int i=n; i>=0; i--)
#define FORdi(start, end) for(int i= start; i>=end; i--)
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// ll gcd(ll a, ll b){
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }

// ll lcm( ll a, ll b) {
// 	ll prod = (a * b) % mod;
// 	return (prod / gcd(a, b));
// }

// bool ispowerof2(ll n){
//    if(n==0)
//     return false;
//    return (ceil(log2(n)) == floor(log2(n)));
// }

// ll power(ll value1, ll power1) {
// 	if (power1 == 0)
// 		return 1LL;
// 	if (power1 == 1)
// 		return value1;
// 	if (power1 % 2 == 0) {
// 		ll x = power(value1, power1 >> 1);
// 		ll y = x * x;
// 		return y;
// 	}
// 	else {
// 		ll x = power(value1, power1 - 1);
// 		ll val = value1 * x;
// 		return val;
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

// ll nextPowerOf2(ll n){
// 	if (n == 1)
// 		return 0;
// 	ll count = 0;
// 	if (n && !(n & (n - 1)))
// 		return n;
// 	while ( n != 0) {
// 		n >>= 1;
// 		count += 1;
// 	}
// 	return count;
// }

// bool compare(pii one, pii two) {
// 	if (one.F == two.F)
// 		return one.S > two.S;
// 	return one.F < two.F;
// }

void solve() {
	ipn;
	string s;
	cin >> s;
	vvc ans(n, vc(n, '?'));

	for (int i = 0, j = 0; i < n; i++, j++) ans[i][j] = 'X';

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
		yy;
		FOR(n) {
			FORj(0, n)
			cout << ans[i][j];
			cout << endl;
		}
	}
	else
		nn;
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