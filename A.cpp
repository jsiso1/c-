
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



long long MINF = 0ll - 1e18+7;
const int MOD = 1e9+7;
const int INF = 1e9+7;
const int N = 2e5+5;
	
int solve () {
	long long n, l, h;
	cin >> n >> l >> h;
	vector<long long> v(n);
	for (int i = 0; i<n; ++i) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	long long ans1 = 0;
	int j = -1;
	for (int i = 1; i<n && v[i]<l; ++i) {
		if (v[i]+v[i-1] < l) {
			ans1 += i;
		} else {
			if (j==-1) j=i-1;
			while (j>=0 && v[i] + v[j] >= l) j--;
			if (j == -1) break;
			ans1 += j+1;
		}
	}

	long long ans2 = 0;
	j = -1;
	for (int i = 1; i<n && v[i]<h; ++i) {
		if (v[i]+v[i-1] <= h) {
			ans2 += i;
		} else {
			if (j==-1) j=i-1;
			while (j>=0 && v[i] + v[j] > h) j--;
			if (j == -1) break;
			ans2 += j+1;
		}
	}
	
	cout << ans2 - ans1 << endl;
	
	return 0;

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
