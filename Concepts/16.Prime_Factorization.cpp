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
#define vvc vector<vc>ru
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
#define cipn cout<<n<<endl;
#define ip(x) ll x; cin>>x;
#define cip(x) cout<< x<<endl;
#define ipch(ch) char ch; cin>>ch;
#define ips string s; cin>>s;
#define ipst(str) string str; cin>>str;
#define ipv vl a(n); FOR(n) cin>>a[i];
#define ipvb(b, n) vl b(n); FOR(n) cin>>b[i];
#define cipv FOR(n) cout<<a[i]<<" ";
#define srt(a) sort(a.begin(), a.end());
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void primeFactorization(ll n){
	ll m=n;
	map<int, int> cnt;

	// BRUTE FORCE
	// T.C- O(sqrt(n))
	// For t cases, T.C- t*(sqrt(n))
	// for(int i=2; i*i<=m; i++){
	// 	while(n%i==0){
	// 		cnt[i]++;
	// 		n/=i;
	// 	}
	// }
	// 
	// if(cnt.size() == 0){
	// 	cout<<"PRIME NUMBER- ";
	// 	cout<<m<<"^"<<1<<endl;
	// } else {
	// 	if(n!=1){
	// 		cnt[n]++;
	// 	}
	// 	for(pair<int, int> x: cnt){
	// 		cout<<x.first<<"^"<<x.second<<endl;
	// 	}
	// }

	// OPTIMIZATION 1- For t testcases, have sieve before hand
	// Then T.C - t*log(n)
	vector<int> sieve(n+1);
	iota(sieve.begin(), sieve.end(), 0);

	// T.C.- O(log(log(n)))
	for(int i=2; i<=n; i++){
		if(sieve[i]==i){
			for(int j=i*2; j<=n; j+=i){
				sieve[j]=i;
			}
		}
	}
	// T.C- O(log(n))
	while(n!=1){
		cnt[sieve[n]]++;
		n/=sieve[n];
	}

	ll pow_of_2 = 0, odd_fact = 1;

	for(pair<int, int> x: cnt){
		if(x.first == 2){
			pow_of_2 = x.second;
		} else {
			odd_fact *= (x.second+1);
		}
	}

	ll total_fact = odd_fact*(pow_of_2+1);
	cout<<"Number is "<<m<<endl;
	if(total_fact == 2) {
		cout<<"PRIME NUMBER- "<<m<<"^1"<<endl;
	} else {	
		for(pair<int, int> x: cnt){
			cout<<x.first<<"^"<<x.second<<endl;
		}
	}

	cout<<"No. of factors = "<<total_fact<<endl;
	cout<<"No. of odd factors = "<<odd_fact<<endl;
	cout<<"No. of even factors = "<<odd_fact*pow_of_2<<endl;
}

void solve() {
	ipn;

	primeFactorization(n);

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

// ll gcd(ll a, ll b){
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }

// ll lcm( ll a, ll b) {
// 	ll prod = (a * b) % mod;
// 	return (prod / gcd(a, b));
// }

// bool ispowerof2(ll n) {
// 	if (n == 0)
// 		return false;
// 	return (ceil(log2(n)) == floor(log2(n)));
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

// ll nextPowerOf2(ll n) {
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