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
#define pib pair<int, bool>
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
#define ipv(n) vl a(n); FOR(n) cin>>a[i];
#define cipv FOR(n) cout<<a[i]<<" ";
#define srt(a) sort(a.begin(), a.end());
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
	ip(n);
	ip(m);
    ip(k);
    ips;

    bool ans = true;

    // vector of pair of next log or land 
    // & boolean value of if he can swim or not till that
    vector<pib> v;
    v.pb({0, false});

    bool can_swim = false, croc = false;
    for(int i=0; i<s.length(); i++) {
        char x = s[i];
        if(x == 'C') {
            croc = true;
        } else if (x == 'W') {
            v.pb({i+1, can_swim});
            can_swim = !croc && true; 
        } else {
            v.pb({i+1, can_swim});
            can_swim = false;
            croc = false;
        }
    }
    v.pb({n+1, can_swim});

    for(auto x: v) {
        cout<< x.first << " "<<x.second<<endl;
    }
    for(int i=1; i<v.size(); i++) {
        if((v[i].first - v[i-1].first) <= m) {
            continue;
        } else {
            if(v[i].second) {
                k -= ((v[i].first - v[i-1].first) - m);
            } else {
                ans = false;
                break;
            }
        }
    }
    if(k<0) {
        ans = false;
    }

    if(ans) {
        yy;
    } else {
        nn;
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