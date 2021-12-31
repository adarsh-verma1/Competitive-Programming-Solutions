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

// void solve() {
// 	int n;
// 	cin >> n;

// 	string ans =  "";
// 	vector<string> s(n - 2);

// 	FOR(n - 2) cin >> s[i];

// 	if (n == 3) {
// 		ans += s[0][0];
// 		ans += s[0][1];
// 		ans += 'a';
// 	}
// 	else {
// 		ans += s[0][0];
// 		FOR(n - 3) {
// 			if (s[i][1] == s[i + 1][0])
// 				ans += s[i][0];
// 			else {
// 				ans += s[i][1];
// 				ans += s[i + 1][0];
// 			}
// 		}
// 	}
// 	if ((s[n - 2][0] == s[n - 3][1]) && (s[n - 2][0] != s[n - 2][1]))
// 		ans += s[n - 2][1];

// 	cout << ans << endl;
// }

void solve() {
	int n;
	cin >> n;
	string s;
	vector<string> a(n - 2);
	bool flag = true;

	FOR(n - 2) {
		cin >> a[i];
		if (i > 0) {
			if (a[i - 1][1] == a[i][0]) {
				s += a[i - 1][1];
			}
			else {
				flag = false;
				s += a[i - 1][1];
				s += a[i][0];
			}
		}
		else {
			s += a[i][0];
		}
		if (i == n - 3) {
			s += a[i][1];
		}
	}
	if (!flag) {
		cout << s << endl;
	}
	else {
		s += a[n - 3][1];
		cout << s << endl;
	}
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