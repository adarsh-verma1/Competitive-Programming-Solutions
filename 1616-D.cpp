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
#define vf vector<float>
#define vs vector<string>
#define vll  vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pb push_back
#define um unordered_map
#define F first
#define S second
#define ipn ll n; cin>>n
#define ipnvll vll a(n); FOR(n) cin >> a[i];
#define endl "\n"
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define FOR(n) for(int i=0; i<n; i++)
#define FORi(start, n) for(int i= start; i<n; i++)
#define FORj(start, n) for(int j= start; j<n; j++)
#define FORd(n) for(int i=n; i>=0; i--)
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

// bool isPossible(vll h, ll ans, ll l, ll r) {
// 	ll n = h.size();
// 	FOR(n - 2) {
// 		if (h[i] >= ans)
// 			continue;
// 		ll diff = max(((ans - h[i]) / 3) * 2, ans - h[i + 1]);
// 		ll total = (diff / 2) * 3;
// 		if (h[i + 2] - total >= 0) {
// 			h[i] +=  diff;
// 			h[i + 1] += (diff / 2);
// 			h[i + 2] -= total;
// 		}
// 		else
// 			return false;
// 		cout << i << "---";
// 		FORj(0, n) cout << h[j] << " ";
// 		cout << endl;
// 	}
// 	cout << ans << " -->";
// 	FOR(n) cout << h[i] << " ";
// 	cout << endl;
// 	return true;
// }

struct solution {
	float len;
	float pos;
	float step;
};

solution longestArithProg(vf const& v) {
	solution best = { -1.0, 0.0, 0.0 };

	for (int i = 1; i < v.size(); ++i) {
		unordered_map<float, float> bestForStep;
		for (int j = 0; j < i; ++j) {
			float step = (v[i] - v[j]) / (i - j);
			if (step * (i - j) == v[i] - v[j]) {
				float len = ++bestForStep[step];
				if (len > best.len) {
					best.len = len;
					best.pos = i;
					best.step = step;
				}
			}
		}
	}

	++best.len;
	return best;
}

void solve() {
	int n;
	cin >> n;
	vf a(n);
	FOR(n) cin >> a[i];

	float ans;
	if (n == 1)
		ans = 0;
	else
		ans = n - longestArithProg(a).len ;
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