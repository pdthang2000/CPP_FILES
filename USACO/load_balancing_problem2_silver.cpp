// http://www.usaco.org/index.php?page=viewproblem2&cpid=619
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;

void pdthang2000() {
	ll n, x, y;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (auto &i : v) cin >> i.fi >> i.se;
	sort(v.begin(), v.end());
	// for (auto i : v) {cout << i.fi << ' ' << i.se <<'\n';}
	ll res = LLONG_MAX;
	for (ll i = 0; i < n; ++i) {
		x = v[i].fi + 1, y = v[i].se + 1;
		ll upper_sum = 0, lower_sum = 0;
		for (auto j : v) {
			if (j.se < y) lower_sum++;
			else upper_sum++;
		}
		// qq;see(x);seen(y);see(lower_sum);seen(upper_sum);qq;
		ll up_left = 0, low_left = 0;
		for (auto j : v) {
			if (j.se < y) {
				low_left++;
			} else {
				up_left++;
			}
			// cout << j.fi << ' ' << j.se << '\n';see(low_left);seen(up_left);
			res = min(res, max(max(low_left, up_left), max(lower_sum - low_left, upper_sum - up_left)));
		}
	}
	cout << res;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
	if (MULTI_TESTS) {
		ll Q;
		cin >> Q;
		while (Q--) {
			pdthang2000();
			qq;
		}
	} else {
		pdthang2000();
	}
}
//cout.precision(18);
//cout << fixed;
//mp.reserve(2 ^ n); //use for unordered_map
//mp.max_load_factor(0.1); //use for unordered_map
//struct custom_hash {
//	static uint64_t splitmix64(uint64_t x) {
//		// http://xorshift.di.unimi.it/splitmix64.c
//		x += 0x9e3779b97f4a7c15;
//		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//		return x ^ (x >> 31);
//	}
// 
//	size_t operator()(uint64_t x) const {
//		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//		return splitmix64(x + FIXED_RANDOM);
//	}
//};