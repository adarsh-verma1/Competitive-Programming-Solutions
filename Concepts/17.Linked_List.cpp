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

class Node{
	public: 
		int val;
		Node *next;
	
	Node() {
		val = 0;
		next = NULL;
	}

	Node(int x) {
		val = x;	
		next = NULL;
	}
};

void reverse(Node *prev, Node *curr, Node **head) {
	if(curr->next == NULL){
		*head = curr;
		curr->next = prev;
		return;
	}

	reverse(curr, curr->next, head);
	curr->next = prev;
}

Node * reverseLinkedList(Node *head2) {
	if(head2 == NULL){
		return head2;
	}

	reverse(NULL, head2, &head2);

	return head2;
}

void solve() {
	ipn;
	int x;

	Node *prev = NULL, *head = NULL, *newNode = NULL;
	while(n--){
		cin>>x;
		newNode = new Node(x);
		if(head == NULL) {
			head = newNode;
			prev = head;
		} else {
			prev->next = newNode;
			prev = newNode;
		}
	}	

	cout<<"Linked List: ";
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->val;
		temp = temp->next;
		if(temp != NULL){
			cout<<" -> ";
		}
	}
	cout<<endl;

	Node *slowPtr = head, *fastPtr= head;
	while(fastPtr != NULL && fastPtr->next != NULL){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	cout<<"Middle of Linked List: "<<slowPtr->val<<endl;

	// Iterative Approach
	// Node *temp1 = head->next, *prevPtr = head, *nextPtr = NULL;
	// head->next = NULL; 
	// while(temp1 != NULL){
	// 	nextPtr = temp1->next;
	// 	temp1->next = prevPtr;
	// 	prevPtr = temp1;
	// 	temp1 = nextPtr;
	// }

	// cout<<"Reversed Linked List using Iterative approach: "<<endl;
	// Node *temp2 = prevPtr;
	// while(temp2 != NULL){
	// 	cout<<temp2->val;
	// 	temp2 = temp2->next;
	// 	if(temp2 != NULL){
	// 		cout<<" -> ";
	// 	}
	// }
	// cout<<endl;

	// Recursive Approach
	Node *head2 = reverseLinkedList(head);

	cout<<"Reversed Linked List using Recursive approach: "<<endl;
	Node *temp2 = head2;
	while(temp2 != NULL){
		cout<<temp2->val;
		temp2 = temp2->next;
		if(temp2 != NULL){
			cout<<" -> ";
		}
	}
	cout<<endl;
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