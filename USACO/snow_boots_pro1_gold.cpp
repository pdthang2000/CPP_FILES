// http://www.usaco.org/index.php?page=viewproblem2&cpid=813
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
ll n, b, s, d;
void pdthang2000() {
    cin >> n >> b;
    vector<ll> f(n), res(b);
    set<ll> indices;
    for (ll i = 0; i < n; ++i) {
        cin >> f[i];
        indices.insert(i);
    }

    vector<ll> tiles;
    for (ll i = 1; i < n - 1; ++i) {
        tiles.push_back(i);
    }

    sort(tiles.begin(), tiles.end(), [&](ll x, ll y) { return f[x] > f[y]; });
    
    vector<vector<ll>> v(b, vector<ll>(3));

    for (ll i = 0; i < b; ++i) {
        cin >> s >> d;
        v[i] = {s, d, i};
    }

    sort(v.rbegin(), v.rend());

    // for (auto i : tiles) {
    //     cout << i << ' ';
    // } qq; qq;

    // for (auto i : v) {
	// 	cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
	// } qq;

    ll cur_tile = 0, needed_steps = 1;

    for (auto i : v) {

        while (
            cur_tile < tiles.size() &&
            f[ tiles[cur_tile] ] > i[0]   
        ) {
            ll cur = tiles[cur_tile];
            auto it = indices.find(cur);
            needed_steps = max(needed_steps, *next(it) - *prev(it));
            indices.erase(it);
            cur_tile++;
        }
        res[i[2]] = (i[1] >= needed_steps);
    }

    for (auto i : res) cout << i << '\n';
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
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
    Important technique. Read the code, run examples and try to understand.
    explain:
    - Sort the tiles base on the depth of the snow f. Remove the first and the last depth (= 0)
    - Sort decrease the boots.
    - Loop the boots, with each element we check: 
        + If the depth of the snow > the max depth of tiles => true
        + Else we find the postion of the current tiles that bigger than 
        the current boot. Erase it from the indices. Update the max needed_steps
        (step = next_postion - prev_position (in indices)) and repeat the procedure
        with the next tiles. 
        + If the tile reaches the end. Break and print the answer.
*/