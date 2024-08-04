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
#define mod 1000000007
#define cnt_1bits(val) __builtin_popcount(val)
#define tc int T; cin >> T; while(T--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
	string s;
	cin >> s;

	int sz = s.size();
	int i, l, r;
	int flag;
	for (i = 0; i < sz; i++) {
		if (s[i] == 'a') {
			flag = 1;
			break;
		}
		flag = 0;
	}

	if (flag == 0) {
		cout << "NO" << endl;
		return;
	}

	l = i,  r = i;
	char ch = 'b';

	for (int j = 1; j < sz; j++) {

		if (l + 1 < sz && s[l + 1] == ch)
			l = l + 1;
		else if (l - 1 >= 0 && s[l - 1] == ch)
			l = l - 1;
		else if (r + 1 < sz && s[r + 1] == ch)
			r = r + 1;
		else if (r - 1 >= 0 && s[r - 1] == ch)
			r = r - 1;
		else {
			flag = 0;
			break;
		}
		flag = 1;
		ch++;
	}
	if (flag == 1)
		cout << "YES" << endl;
	else
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