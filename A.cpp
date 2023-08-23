#include <bits/stdc++.h>
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
using ll = long long;
const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const string pi_string = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

const int MOD = 998244353;

class Compare {
	public:
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	}
};

ll POW(ll a, ll b) {
	ll result = 1;
	ll x = a;
	while (b) {
		if (b%2 == 1)
			result = (result*x)%MOD;
		x = (x*x)%MOD;
		b = b >> 1;
	}
	return result%MOD;
}

ll inverse(ll x) {
	return POW(x, MOD-2);
}
const int M = 1e6+10;
const int N = 2250;
ll fact[2*N];
ll invf[2*N];
const long long INF = 1e18;

int v[40];


int gcd(int a,int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

array<int, 3> EUA(int a, int b) {
	int x, y, u, v;
	x = v = 0;
	y = u = 1;

	while (a != 0) {
		int q = b/a;
		int r = b%a;
		int n = x-u*q;
		int m = y-v*q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = n;
		v = m;
	}
	int gcd = b;
	return {b, x, y};
}



void solve() {	
	ll n;
	cin >> n;


	auto x = gcd(15,12);
	debug(x);
	auto y = EUA(3,5);
	debug(y);



} 
int main () 	{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int TC;
	cin >> TC;	
	for (int i=0;i<TC;++i)
		solve();
	return 0;
 
}
