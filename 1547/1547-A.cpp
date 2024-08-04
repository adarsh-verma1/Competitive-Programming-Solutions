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
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
	int xa, ya, xb, yb, xf, yf;
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xf >> yf;

	int ans = 0;
	if (xa == xb) {
		if (xa == xf && ((yf > ya && yf < yb) || (yf > yb && yf < ya)))
			ans = abs(ya - yb) + 2;
		else
			ans = abs(ya - yb);
	}
	else if (ya == yb) {
		if (ya == yf && ((xf > xa && xf < xb) || (xf > xb && xf < xa)))
			ans = abs(xa - xb) + 2;
		else
			ans = abs(xa - xb);
	}
	else
		ans = abs(xa - xb) + abs(ya - yb);

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