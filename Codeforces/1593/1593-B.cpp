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

void solve() {
	ll n;
	cin >> n;

	string s = to_string(n);
	int  val1 = 0, val2 = 0, zero_idx = s.length() - 1, five_idx = s.length() - 1;

	while (zero_idx >= 0) {
		if (s[zero_idx--] == '0')
			break;
		else
			val1++;
	}

	while (zero_idx >= 0) {
		if (s[zero_idx] == '0' || s[zero_idx] == '5')
			break;
		else
			val1++;
		zero_idx--;
	}


	while (five_idx >= 0) {
		if (s[five_idx--] == '5')
			break;
		else
			val2++;
	}

	while (five_idx >= 0) {
		if (s[five_idx] == '2' || s[five_idx] == '7')
			break;
		else
			val2++;
		five_idx--;
	}

	cout << min(val2, val1) << endl;
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