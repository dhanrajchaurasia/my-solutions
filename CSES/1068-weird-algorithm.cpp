/* 
--------------------------------------------------------------------------------------------------------------------------
------------------------- This problem has been solved by coderdhanraj (Dhanraj Chaurasia) -------------------------------
--------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define float long double
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define si set<int>
#define msi multiset<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back()
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bk back()
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define FORR(i, a, b, c) for (int i = a - 1; i >= b; i -= c)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define CEIL(x, y) x / y + (x % y != 0)
#define cins(x) for (auto &i : x) cin >> i
#define natural(x, y) iota(all(x), y * (1LL))
#define debug(x) cout << #x << " = " << x << endl
#define debugs(x) cout << #x << "{" << x.ff << ", " << x.ss << "}" << endl
#define cond(x) cout << &("NO\0YES" [3 * x]) << endl
#define google(x) cout << "Case #" << x << ": "
#define ends(x) " \n"[x]
#define endl ends(1)
#define mod (int)(1e9 + 7)
#define mod2 998244353
#define EPS 1e-6
#define INF (int)1e18
const int MAX = 2e5 + 10;

void IOS_ONLINE_JUDGE()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
}

int power(int x, int y, int Mod)
{
    int res = 1;
    x = x % Mod; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % Mod;
        y = y >> 1LL;
        x = (x * x) % Mod;
    }
    return res;
}
/*
--------------------------------------------------------------------------------------------------------------------------
------------------------------------------------- Solution Starts From Here ----------------------------------------------
--------------------------------------------------------------------------------------------------------------------------
*/

void solve()
{
    int n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        n = (n & 1 ? 3 * n + 1 : n / 2);
    }
    cout << 1 << endl;
}

int32_t main()
{
    IOS_ONLINE_JUDGE();
    int ttc = 1;
    while (ttc--)
    {
        auto start_time = chrono::high_resolution_clock::now();
        solve();
        cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms." << endl;
    }
    return 0;
}