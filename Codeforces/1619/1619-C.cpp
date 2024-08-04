
/*
	Author: ADARSH VERMA
	Codeforces: adarsh_verma_
	Codechef: adarsh_verma_
	Leetcode: adarsh_verma_
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
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

// bool isPrime(int n)
// {
// 	if (n <= 1)
// 		return false;
// 	if (n <= 3)
// 		return true;

// 	if (n % 2 == 0 || n % 3 == 0)
// 		return false;

// 	for (int i = 5; i * i <= n; i = i + 6)
// 		if (n % i == 0 || n % (i + 2) == 0)
// 			return false;

// 	return true;
// }

void solve() {
	ll a, s;
	cin >> a >> s;

	string sum = to_string(s);
	string num1 = to_string(a);
	string ans = "";

	int i = sum.size() - 1;
	int j = num1.size() - 1;

	while (i >= 0 && j >= 0) {
		int val1 = sum[i--] - '0';
		int val2 = num1[j--] - '0';

		// cout << val1 << " " << val2 << endl;
		if (val2 > val1) {
			if (i >= 0)
				val1 = 10 + val1;
			i--;
		}
		// cout << val1 << " " << val2 << " " << val1 - val2 << endl;
		ans = to_string(val1 - val2) + ans;
	}
	while (i >= 0) {
		int val1 = sum[i--] - '0';
		ans = to_string(val1) + ans;
	}

	// reverse(ans.begin(), ans.end());
	// cout << ans << endl;
	ll temp = stoll(ans);

	// cout << temp << " ";
	string num2 = to_string(temp);
	i = num1.size() - 1;
	j = num2.size() - 1;
	string res = "";
	while (i >= 0 && j >= 0) {
		int val1 = num1[i--] - '0';
		int val2 = num2[j--] - '0';

		// cout << val1 + val2 << " ";
		res = to_string(val1 + val2) + res;
	}

	while (i >= 0) {
		int val1 = num1[i--] - '0';
		res = to_string(val1) + res;
	}

	while (j >= 0) {
		int val2 = num2[j--] - '0';
		res = to_string(val2) + res;
	}

	// reverse(res.begin(), res.end());
	// cout << res << endl;
	if (res == sum)
		cout << temp << endl;
	else
		cout << -1 << endl;
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