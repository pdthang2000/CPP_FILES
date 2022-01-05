// http://www.usaco.org/index.php?page=viewproblem2&cpid=592
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
ll n, t, x, y;
vector<ll> v;

bool work_right(ll cur, ll rad) {
    ll p = 0;
    while (cur < v.back()) {
        while (p + 1 < n && v[p + 1] <= cur + rad) p++;
        if (v[p] == cur) {
            return false;
        }
        cur = v[p];
        rad -= 2;
    }
    return true;
}

bool work_left(ll cur, ll rad) {
    for (auto &i : v) i *= -1;
    reverse(v.begin(), v.end());
    bool ans = work_right(-cur, rad);
    reverse(v.begin(), v.end());
    for (auto &i : v) i *= -1;
    return ans;
}

void pdthang2000() {   
    cin >> n;
    v.resize(n);
    for (auto &i : v) {
        cin >> t;
        i = (t << 1);
    }
    sort(v.begin(), v.end());
    ll L = 0, R = 2e9;
    while (L <= R) {
        ll rad = (L + R) >> 1;
        ll l = v.front();
        ll r = v.back();
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (work_right(mid, rad)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (work_left(l, rad)) {
            R = rad - 1;
        } else {
            L = rad + 1;
        } 
    }
    cout << L / 2 << '.' << (L % 2 ? 5 : 0);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
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

/*
    explain: 
        - Because the radius can be float like : x.5, we multiple all the elements with 2. 
        - Binary search the radius,
            + With each radius, binary search the leftmost position where it causes the chain to the rest of the right
            hay bales. 
            + When we have that position. Check if it can exploded all the hay bales to the left. 
            + If it can, decrease the radius, else increase the radius.
        - Remember to modify the answer.
*/