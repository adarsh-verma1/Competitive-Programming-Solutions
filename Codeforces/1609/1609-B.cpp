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
#define vl  vector<ll>
#define vvi vector<vi>
#define vvl  vector<vl>
#define vvc vector<vc>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pb push_back
#define um unordered_map
#define F first
#define S second
#define endl "\n"
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define FOR(n) for(int i=0; i<n; i++)
#define FORi(start, n) for(int i= start; i<n; i++)
#define FORj(start, n) for(int j= start; j<n; j++)
#define FORd(n) for(int i=n; i>=0; i--)
#define FORdi(start, end) for(int i= start; i>=end; i--)
#define ipn ll n; cin>>n;
#define ip(x) ll x; cin>>x;
#define ipch(ch) char ch; cin>>ch;
#define ips string s; cin>>s;
#define ipst(str) string str; cin>>str;
#define ipv vll a(n); FOR(n) cin>>a[i];
#define srt(a) sort(a.begin(), a.end());
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
	ip(q);
	ips;
	ll cnt = 0;

	// vl a(n, -1);
	// FOR(n - 2) {
	// 	if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
	// 		a[i] = 1;
	// 		i += 2;
	// 		cnt++;
	// 	}
	// }

	// FOR(q) {
	// 	ip(pos);
	// 	ipch(ch);
	// 	pos--;
	// 	if (ch == s[pos]) {
	// 		cout << cnt << endl;
	// 		continue;
	// 	}

	// 	if (ch == 'a') {
	// 		if (pos - 1 >= 0 && a[pos - 1] == 1) {
	// 			cnt--;
	// 			a[pos - 1] = -1;
	// 		}
	// 		else if (pos - 2 >= 0 && a[pos - 2] == 1) {
	// 			cnt--;
	// 			a[pos - 2] = -1;
	// 		}
	// 		if (pos + 2 < n && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
	// 			cnt++;
	// 			a[pos] = 1;
	// 		}
	// 	}
	// 	else if (ch == 'b') {
	// 		if (a[pos] == 1) {
	// 			cnt--;
	// 			a[pos] = -1;
	// 		}
	// 		else if (pos - 2 >= 0 && a[pos - 2] == 1) {
	// 			cnt--;
	// 			a[pos - 2] = -1;
	// 		}
	// 		if (pos - 1 >= 0 && pos + 1 < n && s[pos - 1] == 'a' && s[pos + 1] == 'c') {
	// 			cnt++;
	// 			a[pos - 1] = 1;
	// 		}
	// 	}
	// 	else {
	// 		if (a[pos] == 1) {
	// 			cnt--;
	// 			a[pos] = -1;
	// 		}
	// 		else if (pos - 1 >= 0 && a[pos - 1] == 1) {
	// 			cnt--;
	// 			a[pos - 1] = -1;
	// 		}
	// 		if (pos - 2 >= 0 && s[pos - 2] == 'a' && s[pos - 1] == 'b') {
	// 			cnt++;
	// 			a[pos - 2] = 1;
	// 		}
	// 	}
	// 	s[pos] = ch;
	// 	cout << cnt << endl;
	// }

	FOR(n) {
		if (s.substr(i, 3) == "abc")
			cnt++;
	}
	FOR(q) {
		ip(pos);
		ipch(c);
		pos--;
		for (int j = max(0LL, pos - 2); j <= pos && j + 2 <= n; j++) {
			if (s.substr(j, 3) == "abc")
				cnt--;
		}
		s[pos] = c;
		for (int j = max(0LL, pos - 2); j <= pos && j + 2 <= n; j++) {
			if (s.substr(j, 3) == "abc")
				cnt++;
		}
		cout << cnt << endl;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt" , "r" , stdin);
	freopen("Output.txt" , "w" , stdout);
#endif
	fast;
	// tc{
	solve();
	// }
	return 0;
}