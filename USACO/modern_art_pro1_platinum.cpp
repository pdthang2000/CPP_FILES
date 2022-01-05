// http://www.usaco.org/index.php?page=viewproblem2&cpid=744
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = (ll)1e6 + 5;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll n, x, cur_color, res;
ll a[2021][2022], c[MAX_N], p[2021][2022];
ll t[MAX_N], b[MAX_N], r[MAX_N], l[MAX_N];

void show() { 
    return;
    for (ll i = 1; i <= n + 1; ++i) {
        for (ll j = 1; j <= n + 1; ++j) {
            if (p[i][j] < 0 || p[i][j] > 9)
             cout << p[i][j] << ' ';
            else cout << ' ' << p[i][j] << ' ';
        } UWU;
    } UWU;
}

void pdthang2000() {
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> x;
            a[i][j] = x;
            if (x == 0) continue;
            if (!c[x]) {
                cur_color++;
                t[x] = b[x] = i;
                l[x] = r[x] = j;
            } else {
                t[x] = min(t[x], i);
                b[x] = max(b[x], i);
                l[x] = min(l[x], j);
                r[x] = max(r[x], j);
            }
            c[x]++;
        }
    }

    if (cur_color == 1) {
        cout << n * n - 1;
        return;
    }

    if (cur_color == 0) {
        cout << 0;
        return;
    }

    res = n * n - cur_color;

    for (ll i = 1; i <= n * n; ++i) {
        if (c[i]) {
            x = i;
            p[ t[x] ][ l[x] ]++;
            p[ t[x] ][ r[x] + 1]--;
            p[ b[x] + 1][ l[x] ]--;
            p[ b[x] + 1 ][ r[x] + 1 ]++;
            // show();
        }
    }

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            p[i][j] = p[i][j - 1] + p[i][j];
        }
    }

    show();

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            p[j][i] = p[j - 1][i] + p[j][i];
        }
    }

    show();

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (p[i][j] == 0) continue;
            if (p[i][j] >= 2) {
                c[a[i][j]] = 0; 
            }
        }
    }

    for (ll i = 1; i <= n * n; ++i) {
        if (c[i]) {
            res++;
        }
    }
    
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    if (MULTI_TESTS) {
        ll Q;
        cin >> Q;
        while (Q--) {
            pdthang2000();
            endl;
        }
    } else {
        pdthang2000();
    }
}
/*
    explain: 
        - Mark the area of each color, count the number of existed color.
        - Check the special cases.
        - Add (n * n - cur_color) to the answer.
        - Use prefix sum on 2D to calculate the number of layers have been painted on each cell.
        - Check the condition :
            + If the color have a cell with more than 2 layers and the top layer is the color itself.
            Then it can not be drawn first. Mark this number.
        - Loop again to add all the colors have not been marked and add to the answer.
*/
